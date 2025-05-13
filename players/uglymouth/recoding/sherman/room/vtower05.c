#include "../defs.h"

inherit "room/room";

void reset( int arg ) {
  clone_list = ({
    1, 2, "vampire guard", MON_DIR + "vguard", 0,
  });
  set_light( 1 );
  short_desc = "On the third floor of a black tower.";
  long_desc = "You have climbed to the third floor of the black tower. From "
    + "the looks, this once was the weapons chamber. A trapdoor that is no "
    + "longer present used to prevent entrance from below. Empty weapon "
    + "racks and shelves for armour are now empty an unused. Stairs lead "
    + "up and down.\n";
  dest_dir = ({
    ROOM_DIR + "vtower06", "up",
    ROOM_DIR + "vtower04", "down",
  });
  items=({
    "tower", "You are inside it",
    "weapons chamber", 
      "It is no longer used as such. Actually it's no longer in use all",
    "trapdoor", "Only a pair of rusty hinges indicate its former presence",
    "racks", "Crudely made frames used to store weapons in",
    "shelves", "just some old dusty shelves",
    "stairs", "A wide, spiralling flight of stone stairs",
  });
  ::reset( arg );
  replace_program( "room/room" );
}

