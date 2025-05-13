#include "/players/matt/defs.h"

inherit "/room/room";

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "City Entrance";
  long_desc =
    "    This is Dyolf City, a bustling center of activity. Smoke\n" +
    "from cookfires rises slowly into the sky, the streets are\n" +
    "filled with people doing errands and going about their daily\n" +
    "tasks, and the voices of merchants and vendors rise above the\n" +
    "din and advertise their many wares.\n" +
    "    You happen to be standing on Main Street, which begins\n" +
    "here and runs west. Shops are all around you, and the city\n" +
    "gates stand to the east.\n";

  dest_dir = ({
    NWCITY + "rooms/mainst01", "west",
  });

  items = ({
    "city", "Dyolf City, a busy, heavily-populated place",
    "smoke", "Dark smoke coming from the many cookfires here",
    "cookfires", "The scents of delicious foods rise from the fires",
    "sky", "The sky is clear and deep blue",
    "streets", "Though busy, the streets are kept very clean",
    "people", "The inhabitants of Dyolf City",
    "merchants", "Street merchants selling their wares",
    "vendors", "Vendors advertising their wares",
    "street", "Main Street runs east-west, and starts here",
    "shops", "You can see many shops to the west",
    "gates", "The city gates are open, and lead out",
  });
}

init() {
  ::init();
  add_action("enter", "enter");
}

enter(arg) {
  if(arg == "gates") {
    write("You enter the gates, and leave the Dyolf behind you.\n");
    TP->MOVEP("through the gates#" +
	      NWROAD + "rooms/road14");
    return 1;
  }
  write("Enter what?\n");
  return 1;
}
