inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(0);
  short_desc = "Clearing";
  long_desc =
    "    You stand in the middle of a dark clearing. A foul stench\n" +
    "permeates the air here, making it difficult to breathe. The\n" +
    "same unnatural silence hangs over this place, and you cannot\n" +
    "help but be overcome by a feeling of utter dread.\n";
  smell = "You come close to retching as you breathe in the foul air.";

  dest_dir = ({
    NWFORESTA + "rooms/a11", "northeast",
  });

  items = ({
    "clearing", "A dense ring of trees surrounds this forest clearing",
  });

  clone_list = ({
    1, 1, "beholder", NWFORESTA + "monsters/beholder", 0
  });
  ::reset(arg);
  replace_program("/room/room");
}
