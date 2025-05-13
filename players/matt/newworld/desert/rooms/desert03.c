inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Barren Land";
  long_desc =
    "    You stand in the middle of a very dry and barren land. No\n" +
    "plants can grow in the cracked, arid earth save a few hardy\n" +
    "cacti. Flies buzz around your head and waves of heat seem to\n" +
    "radiate from the ground itself, making you sick and dizzy.\n";

  dest_dir = ({
    NWDESERT + "rooms/waste02", "west",
    NWDESERT + "rooms/scrub02", "east",
    NWDESERT + "rooms/scrub03", "north",
    NWDESERT + "rooms/desert02", "south",
    NWDESERT + "rooms/waste03", "northwest",
    NWDESERT + "rooms/waste01", "southwest",
    NWDESERT + "rooms/desert01", "southeast",
  });

  items = ({
    "earth", "The ground here is extremely dry and barren",
    "ground", "Nothing grows from the wasted ground",
    "cacti", "The only plants which can survive here",
    "flies", "Large and disgusting flies buzzing in your ears",
  });
  replace_program("/room/room");
}
