inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Outside Dyolf City";
  long_desc =
    "    You stand just outside the gates into Dyolf City. The city\n" +
    "looks huge, and its grey stone walls tower over you. Heavily\n" +
    "armed guards patrol the tops of the walls, protecting the city's\n" +
    "inhabitants from unwanted visitors, and over them you see smoke\n" +
    "from the cookfires curling its way up into the sky. The air is\n" +
    "filled with the sounds of wagon wheels and busy people.\n";

  dest_dir = ({
    NWROAD + "rooms/road13", "east",
  });

  items = ({
    "road", "This is a well-used path into the city",
    "gates", "The gates stand open, inviting you to enter",
    "walls", "These thick walls are made of huge grey stones",
    "guards", "The guards look tough but friendly. One waves to you",
    "smoke", "Wisps of dark smoke rise into the sky",
    "city", "Dyolf City, large and well-populated",
  });
}

init() {
  ::init();
  add_action("enter", "enter");
}

into_city() {
}

enter(arg) {
  if(arg == "city" || arg == "dyolf" ||
     arg == "dyolf city" || arg == "gates") {
    write("You enter the gates of Dyolf City.\n");
    TP->MOVEP("through the city gates#" + NWCITY + "rooms/entrance");
    return 1;
  }
  write("Enter what?\n");
  return 1;
}
