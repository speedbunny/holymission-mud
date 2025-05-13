inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(0);
  short_desc = "Dark Forest";
  long_desc =
    "    The sounds of the forest seem unusually loud here, clear\n" +
    "and distinct. Though there is no birdsong, you can hear the\n" +
    "chirps and hums of the insects as well as a few eerie sounds\n" +
    "that you cannot quite place. The trees stand close together\n" +
    "here, but there is a small opening to the west.\n";

  dest_dir = ({
    NWFORESTA + "rooms/a11", "west",
    NWFORESTA + "rooms/a05", "north",
  });

  items = ({
    "forest", "You stand within the Western Forest",
    "opening", "A narrow aperture in the crowd of trees",
    "trees", "Densely packed trees",
  });
  replace_program("/room/room");
}
