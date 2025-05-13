inherit "room/room";
#include "/players/mangla/defs.h"
 
object obj;
int found;
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="The shore of Quite River";
    long_desc="You are standing at the shore of Quite River.\n" +
     "All around you are steep cliffs , no chance to climb them .\n"+
     "A heap of sand lies at the rocks.\n"+
     "There is a sign sticking in the sand.\n";
    items=({
      "heap","It's an ordinary heap of sand",
      "sand","It's an ordinary heap of sand",
      "sign","It's written in the common language"
    });
 
 
}
init() {
::init();
  add_action("swim","swim");
  add_action("dig","dig");
  add_action("read","read");
}
 
dig(str) {
  if(str!="sand" && str!="heap") return;
   say(this_player()->query_name()+" digs around in the sand.\n");
   if(!found && !random(5)) {
     write("It seems that you got something.\n"); 
     obj=clone_object("players/kelly/obj/part3");
     move_object(obj,this_object());
     found=1;
     return 1;
   }
   write("You found nothing.\n");
   return 1;
}
 
swim() {
 write("Although the water is cold you start to swim.\n");
   TP->MOVEP("into the water#players/bobo/krooms/wastelands/river3");
 return 1;
}

read(str) {
  if(str!="sign") return;
  say(this_player()->query_name()+" reads the sign.\n");
  write("The sign reads: Swimming on your own risk.\n");
  return 1;
}
