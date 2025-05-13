#include "std.h"
#undef EXTRA_LONG
#define EXTRA_LONG\
    if (str == "skeleton") {\
write("You see a light coming from the head.\n");\
return;\
    }\
    if (str == "head") {\
    write("The eye in the head resembles a peephole.\n");\
    return;\
}\
     if (str == "peephole") {\
write("You look into the peephole and see\n" +\
    "another eye staring back at you!\n");\
write("You are so startled that you run from the room.\n");\
say(call_other(this_player(), "query_name") +\
     " runs from the room screaming!\n");\
  call_other(this_player(), "move_player", "down#/players/animal/evil5");\
return;\
    }\
     if (str == "note") {\
write("The note reads 'Manx, please do not allow\n");\
write("anyone to bother me, especially mortals!'\n");\
return;\
}
 
id(str) {
return str == "skeleton" || str == "head" || str == "note" || str =="peephole";
}
 
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
 
extra_init() {
     add_action("knock", "knock");
}
 
knock(str) {
     if (str == "three times") {
     write("You hear a loud growl from the north.\n");
     say("You hear a loud gowling coming from the north.\n");
     write("The wall slides open and a LARGE claw grabs you.\n");
say(call_other(this_player(), "query_name") + " is grabbed by a claw.\n");
     say("They are pulled from the room.\n");
     write("You are pulled into a secret room.\n");
   move_object(this_player(), "players/animal/evil22");
   call_other(this_player(), "look");
     return 1;
 }
     return 0;
}
 
ONE_EXIT("players/animal/evil5", "down",
     "The treasure room",
  "The treasure room\n" +
  "\n" +
  "    This is the treasure room of the cats.\n" +
  "    This room does not look like there has ever been\n" +
  "    much treasure stored here.\n" +
  "    You wonder where could all the treasure be?\n" +
  "    As you look around, you notice a few things lying around.\n" +
  "    There are some broken weapons and some rusty\n" +
  "    armour lying around.\n" +
  "    There is also a note lying here.\n" +
  "    You also see skeletons chained to the wall.\n" +
  "    One of the skeletons is grinning at you.\n" +
  "\n", 1)
