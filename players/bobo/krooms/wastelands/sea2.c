inherit "room/room";
#include "/players/mangla/defs.h"
 
object obj;
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="In the ocean";
    long_desc="You're swimming in the sea.\n"+
     "To the north lies the shore.\n";
 
}
init() {
::init();
  add_action("dir_north","north");
  add_action("dir_west","west");
  add_action("dir_other","east");
  add_action("dir_other","south");
}
 
 
dir_west() {
 write("You're swimming westwards.\n");
   TP->MOVEP("west#players/bobo/krooms/wastelands/sea3");
 return 1;
}
dir_other() {
 write("You don't dare to swim further!\n");
 return 1;
}
dir_north() {
 write("You leave the water.\n");
   TP->MOVEP("north#plaeyrs/bobo/krooms/wastelands/seashore");
 return 1;
}
