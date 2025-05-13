#include <doorroom.h>
#include "/players/trout/defs.h"

inherit DOOR_ROOM;

void reset( int arg ) {
  switch( RAN( 100 ) ) {
    case 0..25: MO(CO(MM+"/guard1"), TO());
    break;
    case 26..99:
    break;
  }
  ::reset( arg );
  if( arg ) return;

  set_light( 1 );
  short_desc = "Outer Yard";
  long_desc = "You have entered the outer ward. You stand about 20 feet "
    + "from the protective wall. The temple is raised on a pagoda above "
    + "you. Plants grow sparsly around you. There's a gate to the north.\n";
  dest_dir = ({
    ZZ+"/ward3", "west",
    ZZ+"/hall1", "southwest",
    ZZ+"/hall2", "south",
    ZZ+"/hall3", "southeast",
    ZZ+"/ward5", "east",
  });
  hidden_dir = ({
    ZZ+"/gate", "north",
  });
  items= ({
    "wall" "The stone wall surounds the temple",
    "pagoda", "The pagoda lifts the first level above the ground",
    "plants", "Mostly dandelions",
    "gate", "dummy door description",
  });
}

