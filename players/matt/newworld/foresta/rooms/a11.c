inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(0);
  short_desc = "Dark Forest";
  long_desc =
    "    The first thing you notice in this place is its sudden\n" +
    "lack of sound. A complete silence hangs palpably over you,\n" +
    "utter and unnatural. You look over your shoulder uneasily at\n" +
    "the eyes which you think you can see watching you intently\n" +
    "from the shadows, and wonder nervously what could lurk there.\n";

  dest_dir = ({
    NWFORESTA + "rooms/a06", "east",
    NWFORESTA + "rooms/a15", "southwest",
  });

  items = ({
    "eyes", "You can't be sure, but eyes seem to watch your every move",
    "shadows", "Dark, dreadful shadows",
  });
  replace_program("/room/room");
}
