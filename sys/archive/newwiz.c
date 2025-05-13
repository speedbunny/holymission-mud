/* mud@mud.edvz.uni-linz.ac.at Herp aka Herbert Rosmanith */

/*-------------------------*
 * Using object oriented   *
 * class concept           *
 *-------------------------*/

inherit "/sys/appr";

#include "levels.h"
#include "lw.h"

#define TP	this_player()
#define NEWWIZ	"/sys/bin/newwiz/"

string name_of_friend;	/* who is our testplayer */

static void nwiz_commands() {
    add_action("_filter","",1);
    add_action("cindent_file","cindent");
//     add_action("clone", "clone");
    add_action("copyfile","cp");
    add_action("def_testplayer","testplayer");
    add_action("destruct_local_object", "destruct");
    add_action("edit", "ed");
    add_action("heal", "heal");
    add_action("invis", "invis");
    add_action("in_room", "in");	/* Herp: w/ goto u can use in too */
    add_action("list_peoples", "people");
    add_action("load", "load");
    add_action("makedir", "mkdir");
    add_action("movefile", "mv");
//    add_action("new_object","new");
    add_action("removedir", "rmdir");
    add_action("remove_file", "rm");
    add_action("stat", "stat");
    add_action("quests", "quest", 5 );
    add_action("snoop_on", "snoop");
    add_action("teleport", "goto");
    add_action("trace", "trace"); /* Moonchild 250693 */
    add_action("trans", "trans");
    add_action("update_object", "update");
    add_action("vis", "vis");

/* test test test */
    add_action("del_sanction","desanction");
    add_action("dump_sanctions","rights");

/* added moonchild - wizzes may patch their environment variables 220693 */
    add_action("do_setenv","setenv");
    add_action("do_unsetenv","unsetenv");
    add_action("do_printenv","printenv");

/* Matt SEP-24-94: Question/answer system */
    add_action("do_question", "question");
    add_action("do_answer", "answer");

}

void logon(string n,int quiet) {
  ::logon(n,quiet);
  nwiz_commands();
}

int _filter(string str) {

  string theverb;

  theverb=(string)query_verb();

  if(theverb[0..0]=="'" || member(theverb,'.')!=-1)
    return 0;

  if(file_size(NEWWIZ+theverb+".c")>0) 
    if((NEWWIZ+theverb)->main(str))
      return 1;
            
  return ::_filter(str);
}

int cindent_file(string path) {
  if(!path)
    return 0;
  if(path[0]=='~')
    path="/players/"+name+path[1..<1];
  if(!cindent(path))
    return 0;
  return 1;
}

#if 0
static int clone(string str) {
    object ob;
    string file;

    if(!str) {
	write("Clone what object ?\n");
	return 1;
    }

    if(str[0]=='~')
        str="/players/"+name+str[1..strlen(str)-1];
    str=valid_read(str);
    if(!str) {
	write("Invalid file.\n");
	return 1;
    }
    ob=clone_object(str);
    say(TP->query_name_true()+" fetches something from another dimension.\n",
        0,TP,"");

    /* Herp: changed the order (no move_object before transfer any more */

    if(ob)
        if(ob->get())
            transfer(ob, this_object());
        else
            move_object(ob,environment());
/* Do we really need to log this still? Airborne
        log_file("CLONE",query_real_name()+" cloned "+
            str+" at "+ctime(time())+"\n\t to "+file_name(environment(this_player()))+"\n");
*/

    write("Ok.\n");
    return 1;
}
#endif

static int copyfile(string str) {
  string src,dst;

  if(!str || sscanf(str,"%s %s",src,dst)!=2)
    return 0;
  if(str[0]=='~')
    str="/players/"+name+str[1..<1];
  if(dst[0]=='~')
    dst="/players/"+name+dst[1..<1];
  if(!cp(src,dst))
    write("Fail.\n");
  return 1;
}

static int def_testplayer(string arg) {
    object ob,tp;
    string tpn;

    if(!arg && !name_of_friend) {
	write("Give the name please.\n");
	return 1;
    }

    if(name_of_friend) {
	write("You already have a testplayer. The name is "+
	      capitalize(name_of_friend)+".\n");
	return 1;
    }

    if (!(tp=find_player(arg))) {
	write("No such player found.\n");
	return 1;
    }
    if ((tpn=tp->query_testchar()) && tpn!=name) {
	write("This player is already "+capitalize(tpn)+"'s testplayer.\n");
	return 1;
    }
    if (tp->query_exp()) {
	write("This player is a real player.\n");
	return 1;
    }

    name_of_friend=tp->query_real_name();	/* get the testplayer a */
    ob = clone_object("/sys/testp");		/* a new "soul" :-) */
    exec(ob,tp);
    ob->set_friend(name);
    ob->logon(name_of_friend);
    if(ob->set_friend(name)) {
	write("BUG! Coudn't set your testplayer.\n");
	destruct(ob);
	destruct(tp);
	return 1;
    }
    destruct(tp); 
    save_me(1);
    return 1;
}

static int destruct_local_object(string str) {
    object ob;
    if (!str) {
	write("Destruct what ?\n");
	return 1;
    }
    str = lower_case(str);
    ob = present(str, this_player());
    if (!ob)
	ob = present(str, environment(this_player()));
    if (!ob) {
	write("No " + str + " here.\n");
	return 1;
    }
    if(!this_player()->query_wizard()) {
/* Following change in destruct made by Cashimor 291092 */
#if 0
	if((this_player()->query_real_name()!=creator(ob)) {
	    write("You can only destruct your own objects!\n");
	    return 1;
	}
#endif
#if 1
          if ( (this_player()->query_real_name()!=creator(ob))  /* own code */
      && (this_player()->query_real_name()!=creator(environment(ob))) 
      && (this_player()!=environment(ob))) /* in own inventory */
        {
            write("That does not belong to you!\n");
            return 1;
        }
#endif
 
   }
    say(ob->short()+" is disintegrated by "+TP->query_name_true()+".\n",0,TP,
        ob->short() + " has been disintegrated.\n");
    destruct(ob);
    write("Ok.\n");
    return 1;
}

static int edit(string file) {
    string tmp_file;
    if (!file) {
	ed();
	return 1;
    }
    if(file[0]=='~') file="/players/"+name+file[1..strlen(file)-1];
    file = valid_write(file);
    if (!file) {
	write("You can only edit your own files.\n");
	return 1;
    }
    ed(file);
    return 1;
}

static int heal(string str) {
    object ob;
 
    if (!str) ob = this_object();
    else
    {
        it = lower_case(str);
        ob = find_living(it);
    };
    if (!ob) {
	write("No such person is playing now.\n");
	return 1;
    }
    if(ob!=this_player() && !query_wizard()) return 0;
    call_other(ob, "heal_self", 100000);
    tell_object(ob, "You are healed by " + TP->query_name() + ".\n");
    write("Ok.\n");
    return 1;
}

nomask static int invis(string arch) {
    int n_vis,old_vis;
    old_vis=is_invis;
    switch(arch) {
       case "player": n_vis=L_PLAYER; break;
       case "all": n_vis=level-1; break;
       default: n_vis=to_int(arch);
                if(n_vis<1) n_vis=0;
                if(n_vis>=level) n_vis=level-1;
    };
    if ( !n_vis )
       n_vis = level-1;

    if (is_invis==n_vis) {
	tell_object(this_object(), "You are already invisible (level " +
                    is_invis + ").\n");
	return 1;
    }
    is_invis = n_vis;
    tell_object(this_object(), "You are now invisible (level "+is_invis+").\n");
    return 1;
}

static int in_room(string str) {
    string room;
    object old_room;
    string cmd;
    if (!str)
	return 0;
    if (sscanf(str, "%s %s", room, cmd) != 2) {
	write("Usage: in ROOM CMD\n");
	return 1;
    }
    room = valid_read(room);
    if (!room) {
	write("Invalid file name.\n");
	return 1;
    }
    old_room = environment();
    move_object(this_object(), room);
    command(cmd);
    if (old_room)
	move_object(this_object(), old_room);
    else
	write("Could not go back again.\n");
    return 1;
}

int list_peoples() {	/* 921207 Herp: new layout (using printf) */
  object *u,ob;
  int i,j,c,a;
  string *sa,s,rn;

  u=users();
  c=sizeof(u);
  a=c;
  for (i=0;i<c;i++) {
    printf("%-17s",query_ip_number(u[i]));
    if ((j=u[i]->query_level())<99) printf("(%2i)",j);
    else printf("%4i",j);
    if (!(rn=u[i]->query_real_name())) s="Logon";
    else s=capitalize(rn);
    if (u[i]->query_invis()) s="("+s+")";
    printf(" %-12s",s);
    printf("%3i D",u[i]->query_age()/43200);
    if ((j=query_idle(u[i]))>117) {
       printf("%4i:%'0'2i",j/60,j%60);
       a--;
    }
    else printf(" active");
    if (!(ob=environment(u[i]))) s="at login";
    else {
      s=file_name(ob);
      if (s=="players/"+rn+"/workroom") s="*";
      else {
        sa=explode(s,"/");
        if (sa[0]=="players")
           if(sa[1]==rn) {
	      sa[0]=0;
	      sa[1]="~";
	   }
           else sa[0]="&";
       
        s=implode(sa,"/");
      }
    }
    printf(" %s\n",s);
  }
  printf("%'-'14 i players (%i active) %'-'38s ---\n",
          c,a," "+query_load_average());
  return 1;
}

static int load(string str) {
    if (!str) {
	write("Load what ?\n");
	return 1;
    }
    if(str[0]=='~') str="/players/"+name+str[1..strlen(str)-1];
    str = valid_read(str);
    if (!str) {
	write("Invalid file name.\n");
	return 1;
    }
    /* We just call a non existing function in the object, and that way
     * force it to be loaded.
     */
    call_other(str, "???");
    write("Ok.\n");
    return 1;
}

static int makedir(string str) {
    if (!str)
	return 0;
    if(str[0]=='~') str="/players/"+name+str[1..strlen(str)-1];
    if (!mkdir(str)) write("Fail.\n");
    return 1;
}

static int movefile(string str) {
  string src,dst;
  if (!str || sscanf(str,"%s %s",src,dst)!=2) return 0;
  if(src[0]=='~') src="/players/"+name+src[1..strlen(src)-1];
  if(dst[0]=='~') dst="/players/"+name+dst[1..strlen(dst)-1];
  if (rename(src,dst)!=0) write("Fail.\n");
  return 1;
}

static int new_object(string str) {
  object ob,*ob2,env;
  string s,*s2;
  int i;

  if(!str) {
    write("New what object ?\n");
    return 1;
  }
  if(str[0]=='~')
    str="/players/"+name+str[1..<1];
  env=environment(this_object());
  str=valid_read(str);
  if(!str) {
    write("Invalid filename.\n");
    return 1;
  }
  ob2=all_inventory(this_object());
  for(i=0;i<sizeof(ob2);i++) {
      s2=explode(file_name(ob2[i]),"/");
      s=explode(s2[<1],"#")[0];
      if(s==str || ob2[i]->id(str)) destruct(ob2[i]);  /* Check for filename */
  }
  ob2=all_inventory(env);
  for(i=0;i<sizeof(ob2);i++) {
      s2=explode(file_name(ob2[i]),"/");
      s=explode(s2[<1],"#")[0];
      if(s==str || ob2[i]->id(str)) destruct(ob2[i]); 
  }
  ob=find_object(current_path+"/"+str);
  if(ob)
    destruct(ob);
  move_object(ob=clone_object(str),env);
  if (ob->get()) transfer(ob,this_object()); 
  write("Ok.\n");
  return 1;
}

static int removedir(string str) {
    if (!str)
	return 0;
    if(str[0]=='~')
        str="/players/"+name+str[1..<1];
    if (rmdir(str))
	write("Ok.\n");
    else
	write("Fail.\n");
    return 1;
}

int remove_file(string str) {
    if(!str)
	return 0;
    if(str[0]=='~')
        str="/players/"+name+str[1..<1];
    rm(str);
    return 1;
}

static int stat(string name) {
    object ob;
 
    if (!name)
	return 0;
    it = lower_case(name);
    ob = present(name, environment());
    if (!ob || !living(ob))
	ob = find_living(it);
    if (!ob) {
	write("No such person is playing now.\n");
	return 1;
    }
    call_other(ob, "show_stats", 0);
    return 1;
}

static int quests(string name) {
    object ob;
 
    if (!name)
	return 0;
    it = lower_case(name);
    ob = present(name, environment());
    if (!ob || !living(ob))
	ob = find_living(it);
    if (!ob) {
	write("No such person is playing now.\n");
	return 1;
    }
    call_other(ob, "show_quests", 0);
    return 1;
}

static int snoop_on(string str) {
    object ob;
    int ob_level;
 
    if (!str) {
	snoop(this_player());
	return 1;
    }
    ob = find_player(str);
    if (!ob) {
	write("No such player.\n");
	return 1;
    }
/*   checked int valid snoop
    ob_level = call_other(ob, "query_level");
    if (ob!=this_interactive() && ob_level >= level) {
	write("You fail.\n");
	return 1;
    }
*/
    switch(snoop(this_player(),ob))
    {
        case -1:
	case  0:
            write("You failed!\n");
            break;
        case  1:
            break;
        default:
            write("Unknow return value from efun snoop!\n");
    }
    return 1;
}

int teleport(string dest) {
    object ob;
    if (!dest) {
	write("Goto where ?\n");
	return 1;
    }
    ob = find_living(dest);
    if (ob) {
	ob = environment(ob);
        if ( ob->query_arena() ) {
           write( "You are not allowed to teleport to players in the arena.\n");
           return( 1 );
        }
	move_player("X", ob); // moonie 070993
#if 0
/*
	if (brief)
	    write(call_other(ob, "short", 0) + ".\n");
	else
	    call_other(ob, "long", 0);
*/
	ob = first_inventory(ob);
	while(ob) {
	    if (ob != this_object()) {
		string short_str;
		short_str = call_other(ob, "short");
		if (short_str)
		    write(short_str + ".\n");
	    }
	    ob = next_inventory(ob);
	}
#endif
	return 1;
    }
    dest = valid_read(dest);
    if (!dest || file_size("/" + dest + ".c") <= 0) {
	write("Invalid monster name or file name: " + dest + "\n");
	return 1;
    }
    move_player("X#" + dest);
    return 1;
}

static int trans(string str) {
    object ob,e;
    string out;
 
    if (!str)
	return 0;
    ob = find_living(str);
    if (!ob) {
	write("No such living thing.\n");
	return 1;
    }
    if(!query_wizard() && (ob->query_testchar()!=query_real_name())) {
	write("You can only trans your testcharacter!\n");
	return 1;
    }
    it = str;
    tell_object(ob,capitalize(query_real_name())+
                    " magically transfered you !\n");
    out = call_other(ob, "query_mmsgin", 0);
    if (!out)
	out = call_other(ob, "query_name", 0) +
	    " arrives in a puff of smoke.\n";
    else
	out = call_other(ob, "query_name", 0) + " " + out + ".\n";
    say(out);
    write(out);
    e=environment(ob);
    move_object(ob, environment(this_object()));
    if (e) {
      if(!(out=ob->query_mmsgout()))
	out="disappears in a puff of smoke";
      out=ob->query_name()+" "+out+".\n";
      tell_room(e,out);
    }
    return 1;
}

static int update_object(string str) {
    object ob;
    if (!str) {
	write("Update what object ?\n");
	return 1;
    }
    if (!str) {
	write("Invalid file name.\n");
	return 1;
    }
    if(str[0]=='~') str="/players/"+name+str[1..strlen(str)-1];
    str = valid_read(str);
    ob = find_object(str);
    if (!ob) {
	write("No such object.\n");
	return 1;
    }
    destruct(ob);
    write(str + " will be reloaded at next reference.\n");
    return 1;
}

static int vis() {
    if (!is_invis) {
	tell_object(this_object(), "You are not invisible.\n");
	return 1;
    }
    is_invis = 0;
    tell_object(this_object(), "You are now visible.\n");
    say(TP->query_name() + " " + mmsgin + ".\n", this_object(), this_object());
    return 1;
}

/* Herp: no password available anymore ! */

static int del_sanction(string arg) {
  if(!arg) {
    write("You have to give the name of the wizard.\n");
    return 1;
  }

  if ( master_object()->rem_sanction( query_real_name(), arg ) )
    write("You removed write-rights of "+arg+"!\n");
  else
    write( "Oops, something has gone wrong !\n" );

   return( 1 );
}

int dump_sanctions() { 
   write( master_object()->get_sanctions( query_real_name() ) );
   return( 1 );
}

int do_setenv(string str) {
  string var,sval;
  int ival;
  if(!str)
    return 0;
  if((sscanf(str, "%s %d", var, ival))==2)
    setenv(var, ival);
  else if((sscanf(str, "%s %s", var, sval))==2)
    setenv(var, sval);
  else
    setenv(str);
  write("Ok.\n");
  return 1;
}

int do_unsetenv(string str) {
  write(unsetenv(str) ? "Ok.\n" : "No such environment variable.\n");
  return 1;
}

int do_printenv(string str) {
  if(!str) {
    write("Environment variables:\n\n");
    printenv();
  }
  else
    printenv(str);
  return 1;
}

static int trace(string arg) {
    int ex_time;
    if(!arg)
	write("Trace what?\n");
    else {
	ex_time=command(arg);
	write("Time: " + ex_time + " cycles.\n");
    }
    return 1;
}

/* Matt SEP-24-94: Question/answer system */
static int do_question(string arg) {
  string who;
  string what;
  object targ;

  if(sscanf(arg, "%s %s", who, what) != 2) {
    write("Ask who what?\n");
    return 1;
  }
  if(!targ = find_player(who)) {
    write("Can't find " + capitalize(who) + ".\n");
    return 1;
  }
  if(!targ->query_newwiz()) {
    write(capitalize(who) + " is not a wizard.\n");
    return 1;
  }
  write(lw("You ask " + capitalize(targ->query_real_name()) + ": " +
	   what + "\n"));
  tell_object(targ, lw(capitalize(this_player()->query_real_name()) +
		       " asks you: " + what + "\n" +
		       "Answer using the 'answer' command.\n"));
  log_file(this_player()->query_real_name() + ".qa",
	   lw("You asked " + capitalize(targ->query_real_name()) +
	      ": " + what + "\n"));
  return 1;
}

static int do_answer(string arg) {
  string who;
  string what;
  object targ;
  
  if(sscanf(arg, "%s %s", who, what) != 2) {
    write("Answer who what?\n");
    return 1;
  }
  if(!targ = find_player(who)) {
    write("Can't find " + capitalize(who) + ".\n");
    return 1;
  }
  if(!targ->query_newwiz()) {
    write(capitalize(who) + " is not a wizard.\n");
    return 1;
  }
  write(lw("You answer " + capitalize(targ->query_real_name()) + ": " +
	   what + "\n"));
  tell_object(targ, lw(capitalize(this_player()->query_real_name()) +
		       " answers: " + what + "\n"));
  log_file(targ->query_real_name() + ".qa",
	   lw("  " + capitalize(this_player()->query_real_name()) +
	      " answered: " + what + "\n"));
  return 1;
}

int score() {
   ::score();
   if(is_invis) write(" You are invisible level "+is_invis+".\n");
   else write(" You are visible.\n");
   return 1;
}
