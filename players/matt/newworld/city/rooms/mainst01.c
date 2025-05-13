inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Main Street";
  long_desc =
    "    You find yourself standing on the eastern stretch of Main\n" +
    "Street. This section is crowded, and appears even more so to\n" +
    "the west, where you can make out some kind of city square. The\n" +
    "street itself is worn from years of constant, busy usage.\n";

  dest_dir = ({
    NWCITY + "rooms/mainst02", "west",
    NWCITY + "rooms/entrance", "east",
  });

  items = ({
    "stretch", "This is the eastern stretch of Main Street",
    "street", "The street is worn here",
    "section","This section of Main Street is worn down",
    "square", "You can see a city square to the west",
  });
  replace_program("/room/room");
}
