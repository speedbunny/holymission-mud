inherit "room/room";

int airborne;
int busy;

reset(arg) {
 object carp;

 if (arg) return;
 set_light(1);
 short_desc="Flying Carpet. (On the ground)";
 long_desc="You are on a flying carpet. Strange mathematical patterns are\n"+
           "woven into the carpet, almost as if they are controls of some\n"+
           "kind. There is a circle with arrows pointing into eight directions.\n"+
           "There are also two squares. One green, one red. You can look down.\n";
 items=({"squares","There are two of them. One red, one green",
         "square", "There are two squares. One red, one green",
         "green square","There is a red arrow on it. It points UP",
         "red square","There is a green arrow on it. It points DOWN",
         "circle","You can move the carpet by pressing a direction (e.g. press north)",
         "carpet","A carefully woven carpet"});

 carp=find_living("carpet");
 if (carp) call_other(carp,"set_room",this_object());
}

init() {
 ::init();
 add_action("leave_carpet","leave");
 add_action("leave_carpet","out");
 add_action("leave_carpet","jump");
 add_action("move_dir","press");
 add_action("look_down","look");
 add_action("say_it","say");
 add_action("say_it","'",1);
 }

look_down(arg) {
  object carp;
  object dest;

  carp=find_living("carpet");
  if (!carp) return 0;

  if ((arg=="outside") || (arg=="down")) {
     say(this_player()->query_name()+" looks at the landscape.\n");
     dest = environment(carp);
     if (dest) move_object(this_player(),dest);
     this_player()->look(0);
     move_object(this_player(),this_object());
     return 1;
     }

  return 0;
}

move_dir(arg) {
  object carp;
  string cstr;
  carp=find_living("carpet");
  if (!carp) return 0;

  if (arg=="north") cstr=arg;
  if (arg=="south") cstr=arg;
  if (arg=="west") cstr=arg;
  if (arg=="east") cstr=arg;
  if (arg=="northwest") cstr=arg;
  if (arg=="southwest") cstr=arg;
  if (arg=="northeast") cstr=arg;
  if (arg=="southeast") cstr=arg;
  if (arg=="up") cstr=arg;
  if (arg=="down") cstr=arg;

  if (arg=="square") {
     write("Which square, the green square or the red square ?\n");
     return 1;
     }
  if (arg=="red square") {
     if (airborne) {
        airborne=0;
        write("When you touch the square the carpet lands.\n");
        say(this_player()->query_name()+" presses the red square.\n");
        call_other(carp,"set_airborne",airborne);
        say("The carpet lands softly on the ground.\n",this_player());
        return 1;
     } else {
        write("But the carpet has already landed!\n");
        return 1;
       }
     }
  if (arg=="green square") {
     if (!airborne) {
        airborne=1;
        write("When you touch the square the carpet slowly rises.\n");
        say(this_player()->query_name()+" presses the green square.\n");
        call_other(carp,"set_airborne",airborne);
        say("The carpet slowly rises.\n");
        return 1;
     } else {
        write("But the carpet is already in the air!\n");
        return 1;
       }
     }

  if ((!airborne) && (cstr)) {
     write("But the carpet is not flying!\n");
     return 1;
     }

  if (cstr) {
     say("The carpet moves "+cstr+"\n");
     call_other(carp,"force_carpet",cstr);
     write("Ok.\n");
     } else return 0;
  return 1;
}

msg_port(arg) {

   if (airborne) {
      tell_room(this_object(),arg);
      } else {
      tell_room(this_object(),arg);
      }
}

leave_carpet(arg) {

  object carp;
  object here;

  carp=find_living("carpet");

  if (!carp) {
     write("This should not happen !\n");
     return 1;
     }

  if (airborne) {

        write("The carpet is flying. You would break your neck!\n");
        return 1;

        } else {

        here = call_other(carp,"query_current_room");
        say(this_player()->query_name()+" leaves the carpet.\n");
        write("You step off the carpet.\n");
        move_object(this_player(),here);
        say(this_player()->query_name()+" enters from the carpet.\n");
        return 1;

        }
  return 0;
}

say_it(arg) {
 object carp;
 string verb;

 carp=find_living("carpet");

 verb=query_verb();
 if (arg==0) arg="";
 if (verb[0]=="'"[0]) arg=extract(verb,1)+" "+arg;

 if (carp) {
    call_other(carp,"msg_port","From the carpet,"+this_player()->query_name()+" says: "+arg+"\n");
           }
 write("Ok.\n");
 return 1;
}
