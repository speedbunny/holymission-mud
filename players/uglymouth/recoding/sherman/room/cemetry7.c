#include "../defs.h"

inherit "room/room";

void reset( int arg ) {
  set_light( 1 );
  short_desc = "On the narrow gravel path between the graves.";
  long_desc = "You walk on the narrow gravel path that branched of south "
    + "from the main path through the cemetary. The path is bordered by "
    + "low hedges, beyond which you can see some graves. To the southwest, "
    + "south and southeast, you notice some open places, reserved for "
    + "future graves. They probably won't ever be used now...\n";
  dest_dir=({
    ROOM_DIR + "cemetry4", "north",
  });
  hidden_dir = ({
    ROOM_DIR + "grave10", "southwest",
    ROOM_DIR + "grave11", "south",
    ROOM_DIR + "grave12", "southeast",
  });
  items=({
    "path", 
      "A narrow path of dull red gravel. Weeds are slowly growing over it",
    "hedges", 
      "The once beautiful beech hedges have lost all their leaves and died",
    "cemetery", "Noone has been here in a long time. Weeds grow wildly "
      + "between the graves",
    "places", 
      "Bare patches of the same dirty, dark brown, muddy, depressing clay",
    "open places", 
      "Bare patches of the same dirty, dark brown, muddy, depressing clay",
  });
  ::reset();
  replace_program( "room/room" );
}
