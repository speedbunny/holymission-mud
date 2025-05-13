inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "North Road";
  long_desc =
    "    You are near the border between the forest and the plains,\n" +
    "on a northeast section of North Road. The path continues to the\n" +
    "northeast and the southwest. Though the mountains are somewhat\n" +
    "far off, they still look enormous and dominate the view.\n";

  dest_dir = ({
    NWROAD + "rooms/road06", "northeast",
    NWROAD + "rooms/road04", "southwest",
  });

  items = ({
    "plains", "Grass-covered plains spanning a large area",
    "road", "The road begins to look more worn here",
    "mountains", "Huge icy peaks towering over the landscape",
    "forest", "The forest looks a bit thin here",
  });
}

init() {
  ::init();
  add_action("no_way", "west");
  add_action("no_way", "east");
}
        
no_way() {
  write("The forest is too thick here.\n");
  return 1;
}

