inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Main Street";
  long_desc =
    "    This is Main Street. The city square is just to the west,\n" +
    "a busy mass of people buying, selling, and talking. The city's\n" +
    "inhabitants push past you, walking both eastward back towards\n" +
    "the city gates, and westward into the square.\n";

  dest_dir = ({
    NWCITY + "rooms/square", "west",
    NWCITY + "rooms/mainst01", "east",
  });

  items = ({
    "street", "This is Main Street",
    "square", "A busy city square",
    "mass", "A huge crowd of people",
    "people", "Mostly the city's inhabitants",
    "inhabitants", "Bustling people pushing their way down the busy street",
    "gates", "The city gates lie to the east",
  });
  replace_program("/room/room");
}
