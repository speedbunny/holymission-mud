
#define	TP	this_player()
#define TPP     TP->query_possessive()
#define TPN	TP->query_name()
 
inherit "room/room";
#include "../garden.h" 
int counter;

 
reset(arg) {
  counter=0;

    if (arg) return;
    set_light(0);
    property = "no_teleport";
    short_desc = "In an attic";
    no_castle_flag = 0;
    long_desc = 
  "You are in the attic of a strange building. "+
  "It is slightly chilly and damp here, you can smell "+
  "the odor of rotten wood. To the west you see a dark "+
  "cupboard, and a tiny corridor leads off to the east.\n";
    dest_dir = ({ ROOM+"/attic2","south", 
                  ROOM+"/attic4","east" });

   items = ({"cupboard","A big black cupboard",
             "wood","Black stinking wood",
             "wall","Black wet walls",
             "bottom","A dark wooden bottom"});
}
 
init() {
  ::init();
  add_action("open","open");
  add_action("search","search");
}
search(str) {
  write("You find nothing special.\n");
 return 1;
}
open(str) {
 if (str=="cupboard") {
  if(counter==0) {
    write("As you open the cupboard a strange shrink is rolling out to your feet.\n");
   say("As "+TPN+" opens the cupboard a strange shrink is rolling out to.\n"+
       TPN+"'s feet.\n");
   move_object(clone_object("/players/whisky/garden/obj/shrink"),this_object());

   counter++;
   return 1;
}
  else {
    write("You open the cupboard.\n");
    say(TPN+" opens the cupboard.\n");
    return 1;
 }
 return 1;
}
}

