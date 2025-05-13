inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "Rat infested room";
  long_desc =
"Rat droppings are all over the floor and the scurrying of little feet "+
"is easily heard.  Red eyes peer out at you from the darkness.  The walls "+
"are covered in cobwebs that give the room a draped look.\n";
  set_light(0);
  dest_dir = ({
    sr+"/room209","northwest",
    sr+"/room211","southeast",
  });
  items = ({
    "cobwebs",
    "Thick cobwebs cover the walls",
    "droppings",
    "Piles of rat droppings litter the floor",
    "eyes",
    "Red eyes peer out the gloom reflecting the inhuman soul behind them",
    "floor",
    "The floor is covered in rat droppings and dust",
  });
    ::reset(arg);
    replace_program("room/room");
}
