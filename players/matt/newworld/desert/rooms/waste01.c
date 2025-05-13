#include "/players/matt/defs.h"

inherit NWDESERT + "rooms/waste";

reset(arg) {
  if(arg) return;
  dest_dir = ({
    NWDESERT + "rooms/waste08", "west",
    NWDESERT + "rooms/desert02", "east",
    NWDESERT + "rooms/waste02", "north",
    NWDESERT + "rooms/shadow01", "south",
    NWDESERT + "rooms/waste09", "northwest",
    NWDESERT + "rooms/desert03", "northeast",
    NWDESERT + "rooms/waste07", "southwest",
  });
  clone_list = ({
    1, 2, "lizard", NWDESERT + "monsters/spotlizard", 0,
  });
  ::reset(arg);
  replace_program("/room/room");
}
