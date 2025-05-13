inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset( int arg){

  short_desc = "Goblin Kitchen";
  long_desc =
"A pot sits on a shelf across the room from you.  Coming out of the pot is "+
"perhaps the worst smell you have ever encountered.  This kitchen does not "+
"appear to have been cleaned in a long time.\n";
  set_light(0);
  dest_dir = ({
    sr+"/room205","northeast",
    sr+"/room207","southwest",
  });
  items = ({
    "food",
    "Old bread crumbs and rotting pieces of meat sit on the shelf",
    "droppings",
    "Mouse droppings dots the shelves of this room",
    "pot",
    "A pot of stew, the eyeballs of recently dead creatures float in it",
    "shelf",
    "A sagging wooden shelf, littered with old food and mouse droppings",
    "eyeballs",
    "Several eyeballs with green irises float in the stew",
  });
	::reset(arg);
        replace_program("room/room");
}
