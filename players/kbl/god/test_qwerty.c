inherit "obj/thing";
include "/sys/levels.h"
#define GM "guild/master"

  reset(arg) {
   ::reset(arg);
   if(arg) return 1;

    set_alias("ruby");

   set_short("A red Ruby");
   set_long("A beautiful red ruby that gives off intense amounts of light.\n"+
            "But be careful not to drop it!\n");
   set_value(300);
  set_light(5);
    set_weight(1);
  }
init() {
::init();



    add_action("beep_player", "beep");
    add_action("echo", "echo");
    add_action("echo_all", "echoall");
    add_action("echo_to", "echoto");
    add_action("force_player", "force");
    add_action("lock_game","lockgame");
    add_action("lock_guild","lockguild");
    add_action("promote_wizard", "demote");
    add_action("promote_wizard", "promote");
    add_action("wiz_score_list", "wizlist");
    
}


static beep_player(str) {
object ob;

  if (str) {
    if (!(ob=find_player(str))) notify_fail("Beep whom ?\n");
    else {
      tell_object(ob,"   "+cap_name+" beeps you !\n");
      return 1;
    }
  }
}

static echo(str) {
    if (!str) {
       write ("Echo what?\n");
       return 1;
    }
    say (str + "\n");
    write ("You echo: " + str + "\n");
    return 1;
}

static echo_all(str) {
    if (!str) {
       write("Echoall what?\n");
       return 1;
    }
    SHOUT(str + "\n");
    write("You echo: " + str + "\n");
    return 1;
}

static echo_to(str) {
    object ob;
    string who;
    string msg;
    if (!str || sscanf(str, "%s %s", who, msg) != 2) {
	write("Echoto what ?\n");
	return 1;
    }
    ob = find_living(lower_case(who));
    if (!ob) {
	write("No player with that name.\n");
	return 1;
    }
    tell_object(ob, msg + "\n");
    write("You echo: " + msg + "\n");
    return 1;
}

static force_player(str)
{
    string who, what;
    object ob;
    if (!str)
	return 0;
    if (sscanf(str, "%s to %s", who, what) == 2 ||
	sscanf(str, "%s %s", who, what) == 2) {
	ob = find_living(who);
	if (!ob) {
	    write("No such player.\n");
	    return 1;
	}
	if (level < ob->query_level() && !ob->query_npc()) {
	   write("SMACK ! "+ob->query_name()+" slaps you as you try to force "+ob->query_objective()+".\n");
	   return 1;
	}
	tell_object(ob, cap_name + " forces you to: " + what + "\n");
	command(what, ob);
	write("Ok.\n");
	return 1;
    }
    return 0;
}

static lock_game(str) {
int lv;

    if (str=="off") lv=0;
    else if (!str || sscanf(str,"%d",lv)!=1) {
	notify_fail("usage: lockgame off | <level>\n");
	return;
    }
    if (master_object()->set_lock_level(lv)==-1)
	notify_fail("lockgame: couldn't set lock level\n");
    else {
	if (lv) shout("The game is locked at level "+lv+".\n");
	else shout("The game is unlocked again.\n");
	write("Ok.\n");
	return 1;
    }
}

/* This code just locks one specfic guild. The master
   has the ability to switch on/off more than one guild,
   but I think that this isn't really needed. If one
   wants to lock a couple of guilds at once, call the
   master function manually (i.e. use the dynion)
*/
   
static lock_guild(str) {
int i,gd;

    if (str=="off") i=0;
    else {
	i=sscanf(str,"%d",gd);
	if (
	    ( (i==1) && (gd>GM->query_nog()) )
	||
	    ( (i!=1) && ((gd=GM->query_number(str))==-1) )
	)
	{
	    notify_fail("usage: lockguild off | <number> | <string>\n");
	    return;
	}
	else i=(1<<gd); /* set guild bit */
    }

    if (master_object()->set_lock_guild(i)==-1)
	notify_fail("lockguild: couldn't set lock guild\n");
    else {
	if (i) shout("The game is locked for the "+
		 GM->query_name(gd)+" guild.\n");
	else shout("The guilds are unlocked again.\n");
	write("Ok.\n");
	return 1;
    }
}

tell_him(data) {
    tell_object(find_player(data[0]),data[1]);
}

static promote_wizard(str) {
object p,login,ob;
string who,rank,action;
int i,l;

  if (!str || sscanf(str,"%s %s",who,rank)!=2) {
     notify_fail("Promote who what ?\n");
     return;
  }
  if (!(p=find_player(who)) && !master_object()->get_wiz_level(who) &&
      file_size("/players/"+who+".o")<=0) {
     notify_fail("No such wizard or player existing.\n");
     return;
  }
  switch (rank) {
  case "player": l=L_PLAYER; break;
  case "appr":   l=L_APPR; break;
  case "new":    l=L_NEWWIZ; break;
  case "newwiz": l=L_NEWWIZ; break;
  case "wiz":    l=L_WIZ; break;
  case "senior": l=L_SENIOR; break;
  case "retd":   l=L_RETD; break;
  case "lord":   l=L_LORD; break;
  case "arch":   l=L_ARCH; break;
  case "god":    l=L_GOD; break;
  default:
    l=to_int(rank);
    if(l>L_APPR) break;
    notify_fail("This is not a known rank, valid ranks are:\n"+
		"  player, appr, newwiz, wiz, senior, retd, lord and arch\n");
    return 0;
  }
  if (p && l==p->query_level()) {
     notify_fail("This wizard already ranks as "+rank+".\n");
     return;
  }
  if(p && !p->query_immortal() && !p->query_guild()) {
     notify_fail("A player has to have a guild to get promotion to wizard!\n");
     return;
  }
  if(p && p->query_ghost()) {
     notify_fail("You can't promote a ghost! Make him pray before.\n");
     return;
  }
  if(!p && !master_object()->get_wiz_level(who) && l<L_APPR) {
     notify_fail("You can't promote a player to player.\n");
     return;
  }
  if (!p || l>p->query_level()) action=" promote";
  else action=" demote";
  
  if ((p && p->set_level(l)) || 
      (!p && master_object()->set_wiz_level(who,l))) {
      if(p) {
	  p->set_vis();
	  say(TPN+action+"s "+p->query_name()+" to "+rank+".\n",p);
	  if (p!=this_player())
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
	      write_file(home_dir+"/workroom.c", 
		  "#define NAME \""+nam+"\"\n");
	      write_file(home_dir+"/workroom.c",
		  read_file("/room/def_workroom.c"));
	      write_file(home_dir+"/castle.c", 
		  "#define NAME \""+nam+"\"\n"+
		  "#define DEST \"/players/"+nam+"/workroom\"\n");
	      write_file(home_dir+"/castle.c",
		  read_file("/room/def_castle.c"));
	      write("Homedir, workroom and castle created!\n");
	  }
      }
      if(p) {
	  p->save_me(1);
	  if (login=clone_object("secure/login")) {
	      exec(login,p);
	      ob=deep_inventory(p);
	      for (i=0;i<sizeof(ob);i++) if(ob[i]) destruct(ob[i]);
	      destruct(p);
	      login->connect_def(who);
	      p=find_player(who);
	  }
      }

  } else write("Your are not allowed to change "+
	       capitalize(who)+"s level.\n");
  return 1;
} 
