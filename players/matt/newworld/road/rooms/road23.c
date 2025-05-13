inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Castle Road";
  long_desc =
    "    You stand at the top of the mountain. The area around\n" +
    "you is wide open and covered with a deep layer of snow,\n" +
    "from which small pine trees emerge. The road, which leads\n" +
    "west and north, has been magically cleared of snow here.\n" +
    "    A huge black castle stands directly to the north.\n";

  dest_dir = ({
    NWROAD + "rooms/road24", "north",
    NWROAD + "rooms/road22", "west",
  });

  items = ({
    "road", "North Road is clear and flat here",
    "snow", "The snow lies in a perfectly smooth blanket over the land",
    "trees", "The pine trees are sparse, but a welcome sight",
    "castle", "An enormous black castle in the distance",
  });
  replace_program("/room/room");
}
