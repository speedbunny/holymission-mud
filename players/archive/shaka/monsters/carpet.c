/* Carpet version 1.0 By Xanathar - The Beholder     */
/* REMEMBER to ALTER the path of CARPET (ROOM) .c !!!*/

#define minlevel 20

inherit "/obj/monster";

object room;
int airborne;
int busy;

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("carpet");
    set_alias("flying carpet");
    set_short("A flying carpet. (On the ground)");
    set_race("carpet");
    set_gender(0);
    set_level(19);
    set_hp(55000);
    set_al(0);
    set_ep(314152);
    set_wc(19);
    set_ac(19);
    set_aggressive(0);
  }
}

long() {
    write("It is an old arabian carpet. Complex patterns in both red and green\n"+
          "gives it a magical feeling.");
    if (airborne) {
       write("The carpet is flying high in the air.\n");
       say(this_player()->query_name()+" looks up at the carpet.",this_player());
       } else {
       write("The carpet is on the ground, you could enter it.\n");
       say(this_player()->query_name()+" examines the carpet.\n",this_player());
       }
  }


init() {
 ::init();
 add_action("enter_carpet","enter");
 add_action("info_carpet","info");
 }

enter_carpet(arg) {
 if (arg=="carpet") {
    if (airborne) {
       write("But the carpet is flying !\n");
       return 1;
       } else {
       this_player()->move_player("to the carpet#players/shaka/carpet");
       return 1;
       }
  }
}

info_carpet(arg) {
  write("This is a flying carpet. Ideal for flying over trouble.");
  write("Version 1.0 By Xanathar - The Beholder.");
  return 1;
  }

kill_ear(arg) {
  if ((arg=="carpet") || (arg=="flying carpet")) {
     write("You hit the carpet. NOT !");
     return 1;
     }
  return 0;
  }

catch_tell(str) {

 if (busy==1) return 1;
 busy=1;

 if (room) {
    call_other(room,"msg_port",str);
           }
 busy=0;
}

msg_port(arg) {
 tell_room(environment(this_object()),"\n"+arg);
 return 1;
 }

set_room(arg) {
    room=arg;
    }

set_airborne(arg) {
    airborne=arg;
    if (!arg) {
       say("The carpet lands.\n");
       set_short("A flying carpet. (On the ground)");
       } else {
       say("The carpet rises into the air.\n");
       set_short("A flying carpet. (Flying)");
       }
    }

query_current_room() {
    return environment(this_object());
    }

force_carpet(arg) {
   command(arg);
   }
