inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Bright Forest";
  long_desc =
    "    You are treading the far reaches of the Eastern Forest.\n" +
    "Though there is not much sunlight here, your spirit is still\n" +
    "somehow lifted by an invisible force, a presence of goodness\n" +
    "which you can clearly sense here. You are filled with peace\n" +
    "and pleasure as you enjoy the beautiful forest scene.\n";

  dest_dir = ({
    NWFORESTB + "rooms/b19", "west",
    NWFORESTB + "rooms/b23", "southeast",
  });

  items = ({
    "forest", "The forest is overwhelmingly beautiful here",
    "scene", "The forest scene before you fills you with joy",
  });
  replace_program("/room/room");
}
