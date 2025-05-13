inherit "room/room";
#include "/players/mangla/defs.h"
 
object obj;
 
reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc="In the magic swamps";
    long_desc="You're the in magic swamps.\n"+
     "It seems that you can go everywhere and nowhere.\n";
    dest_dir=({
	"players/bobo/krooms/swamps/swamp5","north",
	"players/bobo/krooms/swamps/swamp12","south",
	"players/bobo/krooms/swamps/swamp3","east",
	"players/bobo/krooms/swamps/swamp2","west",
   });
}
 
init() {
::init();
  add_action("shouting","shout");
  add_action("shouting","tell");
  call_out("sink",15);
}
 
sink() {
  if(environment(this_player())!=this_object()) return;
  write("The ground gets softer and you seem to drown in the mud.\n");
   TP->MOVEP("into nowhere#players/bobo/krooms/swamps/under_sw1");
  return 1;
}
 
shouting() {
  write("You try to shout, but it seems the swamps swallows all your ");
  write("words.\n");
  return 1;
}
