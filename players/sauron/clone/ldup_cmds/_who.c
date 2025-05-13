inherit "/players/sauron/clone/ldup_cmds/extras";

#include "/sys/levels.h"

#pragma strict_types
#pragma save_types

#define FILTER(x)	u=filter_array(users(),x,this_object());
#define RM		"/race/master"
#define C		capitalize
#define ADV		C((string)RM->query_adverb(real_race))
#define TP		this_player()
#define L_LEGEND	50

string pretitle,title,name,race,real_race,testchar;
int level,wiz_level,legend_level,is_invis,idle,afk;

int _mortal(object ob) {
  return (int)ob->query_wiz_level()==WL_PLAYER;
}

int _immortal(object ob) {
  return (int)ob->query_immortal();
}

int _male(object ob) {
  return (int)ob->query_gender()==1;
}

int _female(object ob) {
  return (int)ob->query_gender()==2;
}

int _legendary(object ob) {
  return (int)ob->query_legend_level()?1:0;
  return (int)ob->query_level()>L_LEGEND;
}

int _arena(object ob) {
  return ((int)(environment(ob) && environment(ob)->query_arena()));
}

int whosort(object p1,object p2) {
  int l1,l2;

  l1=(int)p1->query_wiz_level();
  l2=(int)p2->query_wiz_level();
  if(l1)
    l1*=100;
  else
    l1=(int)p1->query_level()+(int)p1->query_legend_level();
  if(l2)
    l2*=100;
  else
    l2=(int)p2->query_level()+(int)p2->query_legend_level();

  return (l1<l2);
}

string make_idle(int idle) {
  int i;
  string str;
  switch(idle) {
    case 0..59:
      str=" - ";
      break;
    case 60..3599:
      i=idle/60;
      str=sprintf("%dm",i);
      break;
    default:
      i=idle/3600;
      str=sprintf("%dh",i);
      break;
  }
  return str;
}

string make_title() {
  string tmp;
  if(wiz_level) {
    if(pretitle && pretitle!="") {
      if(title && title!="")
        tmp=sprintf("%s %s %s",pretitle,C(name),title);
      else
        tmp=sprintf("%s %s",pretitle,C(name));
    }
    else {
      if(title && title!="")
        tmp=sprintf("%s %s",C(name),title);
      else
        tmp=sprintf("%s",C(name));
    }
  }
  else {
    if(pretitle && pretitle!="") {
      if(strlen(title))
        tmp=sprintf("%s %s the %s %s",pretitle,C(name),ADV,title);
      else
        tmp=sprintf("%s %s the %s",pretitle,C(name),ADV);
    }
    else {
      if(title && title!="")
        tmp=sprintf("%s the %s %s",C(name),ADV,title);
      else
        tmp=sprintf("%s the %s",C(name),ADV);
    }
  }
  if(is_invis) {
    if(TP->query_immortal() || TP->query_testchar())
      tmp=sprintf("%s (invis %d)",tmp,is_invis);
    else
      tmp=sprintf("%s (invis)",tmp);
  }
  if(afk) {
    if(TP->query_immortal() || TP->query_testchar())
      tmp=sprintf("%s (afk %s)",tmp,make_idle(idle));
    else
      tmp=sprintf("%s (afk)",tmp);
  }
  else if(idle>=60) {
    if(TP->query_immortal() || TP->query_testchar())
      tmp=sprintf("%s (idle %s)",tmp,make_idle(idle));
    else
      tmp=sprintf("%s (idle)",tmp);
  }
  return tmp;
}

string make_level() {
  switch(wiz_level) {
    case WL_PLAYER..WL_SOCWIZ-1:
      if(legend_level) {
        return (TP->query_immortal() || TP->query_testchar())?
                  testchar?
                    sprintf("  [T %:03d]",legend_level):
                    sprintf("  [L %:03d]",legend_level):
                  "[Legend]";
      }
      else {
        return (TP->query_immortal() || TP->query_testchar())?
                  testchar?
                    sprintf("  [T %:03d]",level):
                    sprintf("  [P %:03d]",level):
                  "[Player]";
      }
      break;
    case WL_SOCWIZ..WL_APPR-1:
      return "[Social]";
      break;
    case WL_APPR..WL_NEWWIZ-1:
      return "[Appr]";
      break;
    case WL_NEWWIZ..WL_WIZ-1:
      return "[NewWiz]";
      break;
    case WL_WIZ..WL_SAGE-1:
      return "[Wizard]";
      break;
    case WL_SAGE..WL_RETD-1:
      return "[Sage]";
      break;
    case WL_RETD..WL_ELDER-1:
      return "[Retd]";
      break;
    case WL_ELDER..WL_ARCH-1:
      return "[ElderWiz]";
      break;
    case WL_ARCH..WL_GOD-1:
      return "[ArchWiz]";
      break;
    case WL_GOD:
      return "[God]";
      break;
    default:
      return "[ArchWiz]";
      break;
  }
}

int _who(string str) {
  string tmp,ind;
  int i,size,idlc;
  object *u;

  if(!str) {
    u=users();
    printf("%|'='79s\n",
           sprintf(" Holy Mission: %s ",ctime()));
  }
  else {
    switch(str) {
      case "mortal":
        FILTER("_mortal");
        break;
      case "immortal":
        FILTER("_immortal");
        break;
      case "male":
        FILTER("_male");
        break;
      case "female":
        FILTER("_female");
        break;
      case "legendary":
        FILTER("_legendary");
        break;
      case "arena":
        FILTER("_arena");
        break;
      default:
        write("Usage: who \
[mortal/immortal/male/female/legendary/arena]\n");
        return 1;
        break;
    }
    if(!sizeof(u)) {
      printf("There are currently no %s players on Holy Mission.\n",str);
      return 1;
    }
    else
      printf("%|'='79s\n",
             sprintf(" %s players on Holy Mission %s ",
                     C(str),ctime()));
  }
  u=sort_array(u,"whosort",this_object());
  size=sizeof(u);
  idlc=0;
  for(i=0;i<size;i++) {
    tmp=(string)u[i]->query_real_name();
    restore_object(sprintf("/p/%s/%s",tmp[0..0],tmp));
    is_invis=(int)u[i]->query_invis();
    testchar=(string)u[i]->query_testchar();
    if(!real_race)
      real_race=race?race:"unknown";
    ind="  ";
    if(query_editing(u[i]))
      ind="E ";
    else if(query_input_pending(u[i]))
      ind="I ";
    else if(_arena(u[i]))
      ind="A ";
    idle=(int)query_idle(u[i]);
    afk=(int)u[i]->is_afk();
    if(idle>60 || afk)
      idlc++;
    printf("%2=s%10=s %-66=s\n",ind,make_level(),make_title());
  }
  printf("%|'='79s\n",sprintf(" %d player%s online (%d active) ",
                              size,size==1?"":"s",size-idlc));
  return 1;
}
