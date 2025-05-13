inherit "room/room";
#include "players/mangla/defs.h"
 
object obj;
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="In the Quiet River";
    long_desc="You're swimming in the Quiet River.\n"+
     "To the east you there's a shore.\n";
 
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
  TP->MOVEP("east#players/bobo/krooms/wastelands/shore1");
 return 1;
}
dir_south() {
 write("You're swimming down the river.\n");
  TP->MOVEP("south#players/bobo/krooms/wastelands/river2");
 return 1;
}
dir_north() {
 write("You try hard, but the streaming is too fast.\n");
 return 1;
}
 
swim(str) {
  if(!str) { write("Which direction?\n"); return 1; }
   else {
   if(str=="s" || str=="south") dir_south();
   if(str=="e" || str=="east") dir_east();
   if(str=="n" || str=="north") dir_north();
  }
}
