inherit "room/room";
#include "corridor.h"
object policeman,club;
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
short_desc="A corridor.";
long_desc=
"You are in a dimly lit corridor.  This area is free of all clutter\n"+
"and reminds you of a hospital in its efficiency.  This is the \n"+
"hallway running down the middle of the cells which are to the \n"+
"north and south of you.\n";
    dest_dir=({
    "players/kelly/rooms/vill/police_office","east",
    "players/kelly/rooms/vill/corridor2","west",
   });
   items=({
   "cells","The poles are made of high-security steel, there's no chance for the prisoners\nto esacpe",
   "cell","The poles are made of high-security steel, there's no chance for the prisoners\nto escape",
   });
}
init() {
::init();
  add_action("north","north");
  add_action("south","south");
  add_init();
}
north() {
 if("players/kelly/rooms/vill/guardroom"->open(1)) 
   this_player()->move_player("north#players/kelly/rooms/vill/cell1n");
 else
   write("The door is closed.\n");
 return 1;
} 
south() {
 if("players/kelly/rooms/vill/guardroom"->open(2))
   this_player()->move_player("north#players/kelly/rooms/vill/cell1s");
 else
   write("The door is closed.\n");
 return 1;
}
