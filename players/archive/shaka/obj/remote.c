/* This is the remote controll for the Ear */
/* Version 1.0 By Xanathar - The Beholder  */

#define minlevel 20

short() {
    return "A shell";
}

long() {
    write("It is a small shell.\n");
    if (call_other(this_player(), "query_level") >= minlevel) {
	write("It is also an Ear controlling device. Commands are :\n"+
              "Spy  <player>     : goto <player> and monitor him\n"+
              "Mode <all/words>) : Switches listening mode\n"+
              "Indicate <...>    : Tell something to the player.\n"+
              "Nuke              : Destroy Ear.\n");
	return 1;
    }
}

init() {
    add_action("spy_on_player", "spy");
    add_action("indicate","indicate");
    add_action("set_mode","mode");
    add_action("nuke_ear","nuke");
}

id(str) {
    return str == "shell" || str == "remote";
}

reset(arg) {
           }

spy_on_player(str) {
    object obj;
    int    ok;

    if (call_other(this_player(), "query_level") < minlevel) {
	write("This is a MUD not a 007 movie !\n");
	return 1;
        }

    obj = find_living("ear");

    if (obj) {
            call_other(obj,"set_commander",this_player());
       ok = call_other(obj,"spy_port",str);
       if (ok) { write("(Ear :Now tracking "+str+".)\n"); } else { write("(Sorry, Unable to locate "+str+".)\n"); }
       return 1;
       }
   write("Errrmmmm..... You forgot to clone EAR !\n");
   return 1;
   }


indicate(str) {
    object obj;
    int    ok;

    if (call_other(this_player(), "query_level") < minlevel) {
	write("So what ?\n");
	return 1;
        }

    obj = find_living("ear");

    if (obj) {
       call_other(obj,"set_commander",this_player());
       call_other(obj,"msg_port","The ear indicates : "+str);
       write("Ok.\n");
       return 1;
       }
    }

set_mode(str) {
    object obj;
    int    ok ;

    if (call_other(this_player(), "query_level") < minlevel) {
	write("This very powerful magic item is for Wizards only.\n");
	return 1;
        }

    obj = find_living("ear");

    if (obj) {
       call_other(obj,"set_commander",this_player());
       if (str=="all") {
          call_other(obj,"mode_port",1);
          write("Mode set to ALL.\n");
          return 1;
          } else {
          call_other(obj,"mode_port",0);
          write("Mode set to Talk only.\n");
          return 1;
          }
    }
  return 0;
}

query_weight() { return 1; }

get() { return 1; }

drop() {
    object obj;

    obj = find_living("ear");
    if (obj) call_other(obj,"set_commander",0);
    return 0;
    }

nuke_ear() {
    object ear;

    if (call_other(this_player(), "query_level") < minlevel) {
	write("You must be joking.\n");
	return 1;
        }

    ear = find_living("ear");
    if (ear) {
       call_other(ear,"msg_port","With a bright flash of magic the Ear is gone !");
       destruct(ear);
       write("Ear self destructed.\n");
       return 1;
       } else {
       write("No Ear here !\n");
       return 1;
       }
  }

query_value() { return 0; }





