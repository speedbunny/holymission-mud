inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "Mountain pass";

  long_desc =
    "The path north leads through a long straight ravine " +
    "where you can just make out sunlight on the other " +
    "end. Here there have been some rock slides and a " +
    "cave has opened in the mountain to the west. " +
    "To the south, the path opens into a large plain.\n";

  dest_dir = ({
    "/players/haplo/ravine/ravine1", "north",
    MINES + "entrance", "west",
    PLAIN + "plane11", "south",
  });

  items = ({
    "path", "A narrow mountain path",
    "pass", "A steep mountain pass, promising a beautiful view ahead",
    "cave","A dark cave entrance is in the western mountain",
    "slides","Large jumbled masses of rocks.  Be glad you were not here "+
             "when they came crashing down the mountain",
    "ravine","A long narrow ravine through the mountains",
    "sunlight", "The sun still lights up the path",
    "plain", "It is to the south",
    "mountain", "It is one of two; the other being to the east",
    "tunnel", "It looks dark in there",
    "tunnel entrance", "It looks dark in there",
    "entrance", "It looks dark in there",
  });

  ::reset(arg);
  replace_program("room/room");
}

