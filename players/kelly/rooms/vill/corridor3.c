inherit "room/room";
#include "corridor.h"
object policeman,club;
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
short_desc="A corridor.";
long_desc=
"You are in a dimly lit corridor.  This area is free from all clutter\n"+
"and reminds you of a hospital in its efficiency.  This is the\n"+
"hallway running down the middle of the cells which are to the\n"+
"north and south of you.\n";
    dest_dir=({
    "players/kelly/rooms/vill/corridor2","east",
    "players/kelly/rooms/vill/guardroom","west",
   });
   items=({
   "cells","The poles are made of high-security steal, no chance for the prisoners to esacpe",
   "cell","The poles are made of high-security steal, no chance for the prisoners to escape",
   });
}
init() {
::init();
  add_action("north","north");
  add_action("south","south");
  add_init();
}
north() {
 if("players/kelly/rooms/vill/guardroom"->open(5)) 
   this_player()->move_player("north#players/kelly/rooms/vill/cell3n");
 else
   write("The door is closed.\n");
 return 1;
} 
south() {
 if("players/kelly/rooms/vill/guardroom"->open(6))
   this_player()->move_player("north#players/kelly/rooms/vill/cell3s");
 else
   write("The door is closed.\n");
 return 1;
}
