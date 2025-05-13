inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Bright Forest";
  long_desc =
    "    The path here leads east, into what looks like a large\n" +
    "clearing, and southwest. The all-pervasive beauty and calm\n" +
    "of this place surrounds you, making you drowsy with its\n" +
    "peaceful serenity. The lushness of your surroundings make\n" +
    "them seem almost unreal, dreamlike.\n";

  dest_dir = ({
    NWFORESTB + "rooms/b19", "east",
    NWFORESTB + "rooms/b15", "southwest",
  });

  items = ({
    "clearing", "A large clearing to the east",
    "path", "An overgrown path",
  });
  replace_program("/room/room");
}
