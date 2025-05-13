#include "../defs.h"

inherit GEN_GRAVE;

void reset( int arg ) {
  short_desc = "A small grave with a broken tomb stone.";
  long_desc = "You are standing in front of a small grave. It has almost "
    + "completely covered by weeds. A broken marble tomb stone stands at "
    + "the head of the grave. The part that broke off is missing.\n";
  hidden_dir = ({
    ROOM_DIR + "cemetry2", "south",
  });
  no_obvious_msg = "The gravel path lies directly south of this grave.\n";
  items=({
    "grave", "It is very small, maybe a child's grave. It is almost "
      + "entirely hidden in weeds",
    "weeds", 
      "Stinging nettles, dandelions and moss make up the majority of plants",
    "tomb stone", 
      "In the red veined marble you can still read \"Natanya R.I\"",
  });
  property = "Natanya";
  ::reset( arg );
  replace_program( GEN_GRAVE );
}
