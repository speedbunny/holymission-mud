inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "City Square";
  long_desc =
    "    You stand in the city square, the main central area of\n" +
    "Dyolf City. Shops and vendors are abundant here; crowds of\n" +
    "people walk in all directions, money and items change hands,\n" +
    "and the air echoes with the shouts of the merchants and\n" +
    "their customers.\n";

  dest_dir = ({
    NWCITY + "rooms/mainst03", "west",
    NWCITY + "rooms/mainst02", "east",
    NWCITY + "rooms/mainshop", "north",
/*
    NWCITY + "rooms/lockerroom", "south",
*/
  });

  items = ({
    "square", "This is the central area of the city",
    "shops", "Many shops surround the square",
    "vendors", "Merchants selling their wares",
    "people", "Crowds of people lining the square",
    "crowds", "There is a huge number of people here",
    "merchants", "They are busy selling",
    "customers", "They are busy buying",
  });
  replace_program("/room/room");
}
