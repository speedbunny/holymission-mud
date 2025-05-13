#include "../defs.h"

inherit "room/room";

mapping vampires;

void reset( int arg ) {
  int i, so;
  string keys;

/*
  if( !vampires )
    vampires = ([ "yurei" : 0, "nicolai" : 0, "drago" : 0, "sashya" : 0 ]);
  for( i=0, so=sizeof( keys=m_indices( vampire ) ); i<so; i++ ) {
    if( vampires[ keys[i] ] ) continue;
    move_object( vampires[ keys[i] ] = clone_object( MON_DIR + keys[i] ),
      this_object() );
  }
*/
  ::reset( arg );
  if( arg ) return;
  
  set_light( 0 );
  short_desc = "In the hall of vampire lord's tower.";
  long_desc = "The hall of the vampire lord's tower is a luxurously "
    + "furnished and decorated chamber. Against the back wall stands a "
    + "countly throne with all the decorum that goes with the title. A "
    + "fine banquet has been served on a big table surrounded by high "
    + "chairs. The room is being illuminted by a dim magical light coming "
    + "from a big chandelier. A doorway in the south wall leads to the "
    + "anteroom.\n";
  dest_dir = ({
    ROOM_DIR + "vtower09", "south",
  });
  hidden_dir = ({
    ROOM_DIR + "vtower11", "north",
  });
  items=({
    "hall", "A hall well becoming any county's court, if it weren't so dark",
    "wall", "A thick stone wall",
    "north wall", "A thick stone wall decorated with a tapestry",
    "throne", "The throne of a count. It's made of jet black ebony wood "
      + "and stands before a black silk tapestry on the north wall",
    "tapestry", "It is painted with blood motives that are horrible to "
      + "look at. A chilly draft reveals a dark spot behind it",
    "spot", "There are plenty of spots to look at. Specify one",
    "dark spot", "It seems to be a hidden opening to another room "
      + "north from here",
    "table", "A big oak table, seating all the count's court",
    "chairs", "Skillfully carved chairs with soft, black cushions",
    "chandelier", 
      "It's intricately made of many crystals which eminate a dim light",
    "doorway", "An open doorway to the anteroom. A curtain hangs before it",
    "curtain", "Thick, expensive black velvet, bordered with gold thread",
    "anteroom", "You cannot see it through the curtain",
  });
}
