inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "North Road";
  long_desc =
    "    You are on North Road in the middle of a large grassy\n" +
    "plain. The wind blows through here, stirring the dust in the\n" +
    "road up into swirling clounds and causing the grass on either\n" +
    "side of you to bend and sway. The path continues north toward\n" +
    "the mountains and south back to the forest.\n";

  dest_dir = ({
    NWROAD + "rooms/road08", "north",
    NWROAD + "rooms/road06", "south",
    NWPLAINS + "rooms/plain03", "east",
    NWPLAINS + "rooms/plain04", "west",
  });

  items = ({
    "plain", "Grass-covered plains surround you",
    "road", "The road looks worn here",
    "mountains", "Huge icy peaks towering over the landscape",
    "forest", "A dense-looking forest",
    "dust", "Swirls of dust surround your ankles",
  });
  replace_program("/room/room");
}
