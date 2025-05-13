#include "../defs.h"

inherit "room/room";

void reset( int arg ) {
  set_light( 1 );
  short_desc = "On a dirt road at the foot of some hills in a dark land.";
  long_desc = "You have arrived at the foot of some hills. The road you are "
    + "on continues north up the slope of the first hill and south towards "
    + "more colourful lands. Everything here has some kind of dark colour "
    + "and even the sun is no more than a pale brownish yellow disc in the "
    + "sky.\n";
  dest_dir = ({
    ROOM_DIR + "darkld03", "north",
    ROOM_DIR + "darkld01", "south",
  });
  items=({ 
    "road", "It looks like a normal dirt road, although noone has gone it "
      + "for a long time",
    "hill", "It's not very steep. You notice the ruins of some houses "
      + "further up its slope",
    "sun", "These lands seem to reject the light and life the sun brings",
  });
  ::reset( arg );
  replace_program( "room/room" );
}
