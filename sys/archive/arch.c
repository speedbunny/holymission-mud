/* mud@mud.edvz.uni-linz.ac.at Herp aka Herbert Rosmanith */

/*-------------------------*
 * Using object oriented   *
 * class concept           *
 *-------------------------*/

inherit  "/sys/wiz";

#include "vt100.h"
#include "defs.h"
#include "/sys/levels.h"

#define TPN     this_player()->query_name()
#define SHOUT(x) gTellstring=x;\
         filter_array(users(),"filter_tell",this_object())
#define ARCH    "/sys/bin/arch/"

int _filter(string str) {
  string theverb,dir;

  theverb=(string)query_verb();
  dir="/players/"+(string)this_player()->query_real_name()+"/bin/";

  if(theverb[0..0]=="'" || member(theverb,'.')!=-1)
    return 0;

// Sauron 301296: Execute commands in an arch's personal bin dir.
  if(file_size(dir+theverb+".c")>0) {
    if((dir+theverb)->main(str))
      return 1;
  }

  else if(file_size(ARCH+theverb+".c")>0) {
    if((ARCH+theverb)->main(str))
      return 1;
  }

  return ::_filter(str);
}

void reset(int arg) {
  ::reset(arg);
}

static void archwiz_commands() {
  add_action("_filter",		"",1);
  add_action("possess_object",	"possess");
  add_action("promote_wizard",	"demote");
  add_action("promote_wizard",	"promote");
  add_action("echo_arch",	"arch");
  add_action("echo_arch",	"arch/");
  add_action("echo_notify",	"notify");
}

void logon(string n,int quiet) {
  ::logon(n,quiet);
  archwiz_commands();
  CD->add_chat(this_object(),-3);     /* notify-line */
  CD->add_chat(this_object(),-2);     /* arch-line */
}

/* add_chat() will be called from secure/master::valid_exec() */

void add_chat() {
  CD->add_chat(this_object(),-3);     /* add to notify-line */
  CD->add_chat(this_object(),-2);     /* add to arch-line */
  ::add_chat();                       /* add to guild/wiz-lines */
}

static void possess_interactive(object pso,object ob) {
  exec(pso,ob);               /* connect the victim */
  exec(ob,this_object());     /* connect us to the victim */
  pso->set_command_modifier();
  snoop(pso,ob);
}

static int possess_object(string str) {

  object ob,pso;

  if(!str) {
    notify_fail("Possess what?\n");
    return 0;
  }
  if(!(ob=find_living(str)) &&
     !(ob=present(str,environment(this_player())))){
    notify_fail("No such object.\n");
    return 0;
  }
  pso=clone_object("/sys/poss");
  move_object(pso,ob);
  pso->init_poss(ob);
  if(interactive(ob))
    possess_interactive(pso,ob);
  else {
    exec(ob,this_object());
    ob->set_command_modifier();
  }
  return 1;
}

static int promote_wizard(string str) {

  object p,login,*ob;
  string who,rank,action;
  int i,l;

  if(!str || sscanf(str,"%s %s",who,rank)!=2) {
    notify_fail("Promote who to what level?\n");
    return 0;
  }
  if(!(p=find_player(who)) && !master_object()->get_wiz_level(who) &&
    file_size(sprintf("/p/%c/%s.o",who[0], who))<=0) {
    notify_fail("No such wizard or player exists.\n");
    return 0;
  }
  switch(rank) {
    case "player":	l=L_PLAYER; break;
    case "appr":	l=L_APPR; break;
    case "new":		l=L_NEWWIZ; break;
    case "newwiz":	l=L_NEWWIZ; break;
    case "wiz":		l=L_WIZ; break;
    case "wizard":	l=L_WIZ; break;
    case "sage":	l=L_SAGE; break;
    case "retd":	l=L_RETD; break;
    case "elder":	l=L_ELDER; break;
    case "arch":	l=L_ARCH; break;
    case "god":		l=L_GOD; break;
    default:
      l=to_int(rank);
      if(l>L_APPR)
        break;
      notify_fail("This is not a known rank, valid ranks are:\n"+
                  "\tplayer, appr, new(wiz), wiz(ard), sage,\n" +
                  "\tretd, elder and arch\n");
      return 0;

  }
  if(p && l==p->query_level()) {
     notify_fail("This wizard already ranks as "+rank+".\n");
     return 0;
  }
  if(p && !p->query_immortal() && !p->query_guild()) {
     notify_fail("A player has to have a guild to get promotion to wizard.\n");
     return 0;
  }
  if(p && p->query_ghost()) {
     notify_fail("You can't promote a ghost. Make them pray first.\n");
     return 0;
  }
  if(!p && !master_object()->get_wiz_level(who) && l<=L_PLAYER) {
     notify_fail("You can't promote a player to player.\n");
     return 0;
  }
  if(!p || l>p->query_level())
    action=" promote";
  else
    action=" demote";

  if((p && p->set_level(l)) ||
     (!p && master_object()->set_wiz_level(who,l))) {
    if(p) {
      p->set_vis();
      say(TPN+action+"s "+p->query_name()+" to "+rank+".\n",p);
      if(p!=this_player())
        call_out("tell_him",1,
                 ({who,"You have been"+action+"d "+rank+" by "+TPN+".\n"}));
    }
    write("You"+action+" "+capitalize(who)+" to "+rank+".\n");
/* 020793 Llort if we promote him to at least NEWWIZ he should have a
   homedir, workroom and castle.
   We have to make that before we connect him to the new player-obj,
   cause afterwards the 'this_player' is set to him!*/
    if(l>L_APPR) {
      string home_dir,tmp,nam;
      nam=who;
      home_dir="/players/"+nam;
      if(file_size(home_dir)!=-2) {
        mkdir(home_dir);
        write_file(home_dir+"/workroom.c","#define NAME \""+nam+"\"\n");
        write_file(home_dir+"/workroom.c",read_file("/room/def_workroom.c"));
        write_file(home_dir+"/castle.c","#define NAME \""+nam+"\"\n\
#define DEST \"/players/"+nam+"/workroom\"\n");
        write_file(home_dir+"/castle.c",read_file("/room/def_castle.c"));
        write("Homedir, workroom and castle created!\n");
      }
    }
    if(p) {
      p->save_me(1);
      if(login=clone_object("/secure/login")) {
        exec(login,p);
        ob=deep_inventory(p);
        for(i=0;i<sizeof(ob);i++)
          if(ob[i])
            destruct(ob[i]);
        destruct(p);
        login->connect_def(who);
        p=find_player(who);
      }
    }
  }
  else
    write("Your are not allowed to change "+capitalize(who)+"s level.\n");
  return 1;
}

static int echo_arch(string str) {
  if(!str) {
    write("On the arch-line:\n\n");
    CD->print_line(-2);
    return 1;
  }
  else if(str=="on" || str=="off") {
    CD->set_line(this_object(),-2,str=="on"?1:0);
    return 1;
  }

  else {
    str="\n[arch] "+capitalize(query_real_name())
                   +(query_verb()=="arch"?" says: ":" ")+str+"\n";
    str=line_format(str,78,5,6," "," "," ","");
    CD->do_chat(-2,str);
    return 1;
  }
}

static int echo_notify(string str) {
  if(!str) {
    write("On the notify-line:\n\n");
    CD->print_line(-3);
    return 1;
  }

  else if(str=="on" || str=="off") {
    CD->set_line(this_object(),-3,str=="on"?1:0);
    return 1;
  }

  else {
    write("The notify-line isn't for talking on.\n");
    return 1;
  }
}
