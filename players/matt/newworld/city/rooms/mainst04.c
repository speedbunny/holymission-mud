inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Main Street";
  long_desc =
    "    You have come to what appears to be the end of Main Street.\n" +
    "To the north lies the open doorway to a large hall, and to the\n" +
    "east you can still see, and hear, the city square. You can see\n" +
    "the entrance to a rather large Arena which is covered in boards.\n" +
    "There is a sign posted on the boards covering the entrance.\n";

  dest_dir = ({
    NWCITY + "rooms/gamehall", "north",
    NWCITY + "rooms/mainst03", "east",
     /* Taken out due to lack of upkeep, players can cause actual death
          Haplo 4-19-95
    NWCITY + "rooms/arena", "south",
      */
  });
  
  items = ({
    "square", "The crowded central area of the city",
   "sign","Arena closed due to massive liability claims",
   "Arena","Large Arena with boards covering the entrance",
   "arena","Large Arena with boards covering the entrance",
    "street", "Main street is a worn, well-used street running through Dyolf",
    "hall", "Many people crowd what looks like a Hall of Games",
    "doorway", "The doorway leads into the hall",
  });
}
