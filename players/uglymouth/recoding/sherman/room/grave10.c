#include "../defs.h"

inherit GEN_GRAVE;

void reset( int arg ) {
  short_desc = "At a bare patch of ground reserved for a new grave.";
  long_desc = "You have come to a bare patch of muddy clay soil, the size "
    + "of a grave. It has never been a need for this place to be a grave, "
    + "and there probably never will be either. There are similar patches "
    + "of ground further east.\n";
  hidden_dir = ({
    ROOM_DIR + "cemetry7", "northeast",
    ROOM_DIR + "grave11", "east",
  });
  no_obvious_msg = "The gravel path lies directly northeast of this place.\n";
  items=({
    "patch", "A patch of the same dark brown clay. It's muddy and nothing "
      + "grows here",
    "soil", "The same old boring clay that seems to be the very fabric "
      + "of these lands",
  });
  empty_grave = 1;
  ::reset( arg );
  replace_program( GEN_GRAVE );
}
