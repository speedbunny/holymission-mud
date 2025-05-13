#include "../defs.h"

inherit "room/room";

void reset( int arg ) {
  set_light( 1 );
  short_desc = "The gateway of a deserted cemetary.";
  long_desc = "You stand in the gateway that leads to a small spooky "
    + "cemetery. A narrow gravel path leads east across the cemetery "
    + "towards a small chapel. Even in daylight, everythings looks dull "
    + "grey. A wide dirt road leads north. You notice an opening in the "
    + "hill west from here.\n";
  dest_dir=({
    ROOM_DIR + "tunnel3", "west",
    ROOM_DIR + "darkld01", "north",
    ROOM_DIR + "cemetry2", "east",
  });
  items=({
    "gateway", "An iron gate, full of symbols, is standing open. Given "
      + "the amount of rust, it probably can't even be closed again",
    "symbols", "Skulls, crossed bones, cherubs, crosses and other things "
      + "common to cemeteries",
    "cemetery", "Noone has been here in a long time. Weeds grow wildly "
      + "between the graves",
    "graves", 
      "Most of them seem neglected. Some tomb stones have fallen over",
    "tomb stones", "You can't see any details from here",
    "path", 
      "A narrow path of dull red gravel. Weeds are slowly growing over it",
    "daylight", 
      "Even the light itself seems be reluctant to illuminate this place",
    "road", "It leads north towards some dark hills",
    "opening", "The dark entrance of a tunnel leading into the hill",
    "hill", "A gloomy hill with a thick vegetation of greyish green "
      + "thistles and bushes",
  });
  ::reset();
  replace_program( "room/room" );
}
