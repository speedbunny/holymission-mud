inherit "room/room";
#include "/players/mangla/defs.h"
 
object obj;
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="In the Quiet River";
    long_desc="You're swimming in the Quiet River.\n"+
     "Here the river leads into the sea.\n"+
     "To the east lies the shore.\n";
 
}
init() {
::init();
  add_action("dir_north","north");
  add_action("dir_south","south");
  add_action("dir_east","east");
  add_action("swim","swim");
}
 
 
dir_east() {
 write("You leave the water.\n");
 TP->MOVEP("east#players/bobo/krooms/wastelands/mouth");
 return 1;
}
dir_south() {
 write("You swim into the ocean.\n");
 TP->MOVEP("south#players/bobo/krooms/wastelands/sea3");
 return 1;
}
dir_north() {
 write("You're swimming up the river.\n");
 TP->MOVEP("north#players/bobo/krooms/wastelands/river2");
 return 1;
}
 
swim(str) {
  if(!str) { write("Which direction?\n"); return 1; }
   else {
   if (str=="n" || str=="north") dir_north();
   if (str=="s" || str=="south") dir_south();
   return 1;
  }
}
 
