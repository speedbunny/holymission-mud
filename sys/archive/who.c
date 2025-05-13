// who() rewritten moonie 190893

#include "/sys/levels.h"
#define FILTER(x) u=filter_array(users(), x, this_object()); break;

int who(string arg) {
  object *u;
  int i,l,pl,flag,j,hlp;
  string line,s,msg;
  if(!arg) {
    u=users();
    msg="====================================================================="
        "==========\n";
  }
  else {
    switch(arg) {
      case "mortal":    FILTER("_mortal");
      case "immortal":  FILTER("_immortal");
      case "male":      FILTER("_male");
      case "female":    FILTER("_female");
      case "incognito": FILTER("_incognito");
//      case "pk":        FILTER("_pk");
      case "legendary": FILTER("_legendary");
      case "arena":     FILTER("_arena");
      default:          write("Usage: who [mortal/immortal/male/female/"
                                "incognito/legendary/arena]\n");
                        return 1; break;
    }
    if(!sizeof(u)) {
      printf("No %s players on Holy Mission currently.\n", arg);
      return 1;
    }
    msg=sprintf("%s players on Holy Mission:\n\n=============================="
        "=================================================\n",
        capitalize(arg));
  }
  u=sort_array(u, "whosort", this_object());
  j=sizeof(u);
  for(i=0;i<j;i++) {
    if(u[i]->query_incognito()) break;
    pl=l;
    l=(int)u[i]->query_level();
    if((pl >99) && (l <= 99))
      msg+="------------------------------------------------------------------"
        "-------------\n";
    switch(l) {
      case -1..99: hlp = l + u[i]->query_legend_level();
                   if ( hlp > 99 ) line = sprintf("[L%i]", hlp-99);
                   else             line = sprintf("[%i]", l);
                   break;
      case 100..119: { line = "[Appr]";           break; }
      case 120..139: { line = "[New]";          break; }
      case 140..159: { line = "[Wiz]";          break; }
//      case 35    :
      case 160..179: {line = "[Sage]";          break; }
       case 180..199:     { line = "[Retd]";        break; }
      case 200..249:  { line = "[Eldr]";         break; }
      case 250   : { line = "[Arch]";           break; }
       case 500  : { line = "[High Arch]";      break; }
      case 1000  : { line = "[God]";            break; }
      default    : { line = "[Arch]";           break; }
    }
    if(!(s=(string)u[i]->query_presentation(0)))
      s=capitalize((string)u[i]->query_real_name());
    msg+=sprintf("%-7=s%-72=s\n", line, s);
  }
  /*HERP: i already contains the index of the first incognito */
  if(i<=j)
    for(flag=arg=="incognito";i<j;i++) {
      if(!u[i]->query_incognito())
        continue;
      if(!flag)
        msg+="----------------------------------------------------------------"
        "---------------\nIncognito:\n";
      flag=1;
      msg=sprintf("%s       %s\n", msg, (string)u[i]->query_presentation(1));
    }
  msg=sprintf("%s============================== %i players online ============"
        "==================\n", msg, j);
  write(msg);
  return 1;
}

status _mortal(object ob)    { return (int)ob->query_level()<30;  }
status _immortal(object ob)  { return (int)ob->query_level()>99;  }
status _male(object ob)      { return (int)ob->query_gender()==1; }
status _female(object ob)    { return (int)ob->query_gender()==2; }
status _incognito(object ob) { return (int)ob->query_incognito(); }
status _pk(object ob)        { return (int)ob->query_is_pk(); }
status _legendary(object ob) { return (int)(ob->query_legend_level() > 0); }
status _arena(object ob)
{ 
   return( (int) (environment(ob) && environment(ob)->query_arena()) );
}

status whosort(object p1, object p2) { 
  int l1, l2;
/*
  return p1->query_incognito() ? 1 : p2->query_incognito() ? 0 :
        (int)p1->query_level() < (int)p2->query_level();
*/
  if ( p1->query_incognito() ) return( 1 );
  if ( p2->query_incognito() ) return( 0 );
  l1 = p1->query_level();
  l2 = p2->query_level();
  if ( p1->query_immortal() ) l1 += 100;
  else                        l1 += p1->query_legend_level();
  if ( p2->query_immortal() ) l2 += 100;
  else                        l2 += p2->query_legend_level();
  return( l1 < l2 );
}
