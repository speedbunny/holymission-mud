#include "../defs.h"

inherit "room/room";

void reset( int arg ) {
  object ob;

  ::reset( arg );
  if( ob = present( "jarlington" ) ) {
    tell_room( TO, "Jarlington says: It's time for a nap...\n"
      + "Jarlington climbs into his coffin and closes the lid.\n" );
    destruct( ob );
  }
  if( arg ) return;

  set_light( 0 );
  short_desc = "Inside a wrecked outhouse.";
  long_desc = "You stand inside what is left of the outhouse after some "
    + "monsters wrecked it. It has been furnished with the most elemental "
    + "things for living. Against the back wall you see an old coffin. "
    + "It looks like this place has been visited recently.\n";
  dest_dir = ({
    ROOM_DIR + "darkld12", "leave",
  });
  items=({ 
    "outhouse", "About six square meters of this building has been left "
      + "upright. It's very drafty and dark",
    "things", "A table, a chair, a small stove, a pan, but oddly enough "
      + "there seems to be no place to sleep",
    "coffin", "A simple oak coffin without decorations. It's closed",
  });
}

