inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(0);
  short_desc = "Dark Forest";
  long_desc =
    "    The air here is moist and muggy. Small gnats and other\n" +
    "bloodsucking insects swarm around your head despite your\n" +
    "efforts to ward them away. It is a bit lighter here, but\n" +
    "still not enough so to see without an extra light source.\n" +
    "    You can hear the bubbling sounds of running water to the\n" +
    "southwest.\n";

  dest_dir = ({
    NWFORESTA + "rooms/a14", "east",
    NWFORESTA + "rooms/a18", "north",
    NWFORESTA + "rooms/a22", "southwest",
  });
  
  items = ({
    "gnats", "Tiny insects buzzing all around you",
    "insects", "Clouds of small insects swarm around your head",
  });

  clone_list = ({
    1, 1, "gnats", NWFORESTA + "monsters/gnats", 0
  });
  ::reset(arg);
  replace_program("/room/room");
}
