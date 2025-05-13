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
    NWDESERT + "rooms/desert02", "west",
    NWDESERT + "rooms/scrub01", "east",
    NWDESERT + "rooms/scrub02", "north",
    NWDESERT + "rooms/desert03", "northwest",
  });

  items = ({
    "earth", "The ground here is extremely dry and barren",
    "ground", "Nothing grows from the wasted ground",
    "cacti", "The only plants which can survive here",
    "flies", "Large and disgusting flies buzzing in your ears",
  });
  clone_list = ({
    1, 3, "beetle", NWDESERT + "monsters/sandbeetle", 0,
  });
  ::reset(arg);
  replace_program("/room/room");
}
