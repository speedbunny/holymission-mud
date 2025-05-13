inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Fork";
  long_desc =
    "    You are at a fork in the road which leads west towards\n" +
    "what looks like a city, north directly into the mountains, and\n" +
    "southeast towards the lowlands. The road itself is at a rather\n" +
    "peculiar angle due to the nature of the landscape, and both\n" +
    "sides are steep and rocky.\n" +
    "    Columns of smoke rise into the air to the west, and a\n" +
    "small sign stands on the east side of the path.\n";

  dest_dir = ({
    NWROAD + "rooms/road11", "west",
    NWROAD + "rooms/road09", "southeast",
    NWROAD + "rooms/road15", "north",
  });

  items = ({
    "city", "The city looks rather large",
    "road", "This is North Road",
    "mountains", "The mountains are rather close now",
    "smoke", "You imagine that it comes from the city's chimneys",
    "sign", "A small wooden sign set into the hillside",
    "columns", "Columns of light smoke to the west",
  });
}

init() {
  ::init();
  add_action("read", "read");
}
        
read(arg) {
  if(!arg) write("Read what?\n");
  if(arg == "sign") {
    write("    There are three arrows on this sign. The one pointing\n");
    write("west reads 'This way to Dyolf City', the north arrow reads\n");
    write("'This way to the Mountains of Sanity', and the southeastern\n");
    write("arrow reads 'The Grasslands'.\n");
  }
  return 1;
}
