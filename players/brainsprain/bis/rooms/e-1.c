inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {
  
  short_desc = "The nobles refreshment room";
  long_desc =
    "Two card tables sit against the northern wall.  One of the tables is "+
    "filled with pitchers of drinks.  The other table is piled high with "+
    "trays containing delectable foods.  To the south is a waiting room.\n";
  set_light(1);
  items = ({
    "room",
    "The waiting room is to the south",
    "tables",
    "Card Tables along the northern wall",
    "wall",
    "The northern wall",
    "pitchers",
    "They are filled with fine wine",
    "trays",
    "All sorts of delectable foods",
    "foods",
    "All sorts of delectable foods",
  });
  dest_dir = ({
    br+"/e-2.c","south",
  });
  ::reset(arg);
  replace_program("room/room");

}

