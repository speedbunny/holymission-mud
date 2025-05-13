inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Outside the Gatehouse";
  long_desc =
    "    You stand before a huge gatehouse made of black stone.\n" +
    "It towers over you, a square-based structure with small\n" +
    "towers at each corner topped with black flags. A small\n" +
    "open doorway is set into its side.\n";

  dest_dir = ({
    NWROAD + "rooms/road24", "south",
  });

  items = ({
    "gatehouse", "The gatehouse of the castle before you",
    "castle", "An enormous black stone castle a ways ahead",
    "stone", "Black stone comprises the gatehouse's design",
    "structure", "The gatehouse of the castle",
    "towers", "Small useless towers, just for show",
    "flags", "Long black flags whipping about in the wind",
    "doorway", "An open doorway leading into the gatehouse",
    "corners", "Each corner is marked with a small tower",
  });
}

init() {
  ::init();
  add_action("enter", "enter");
}
        
enter(arg) {
  if(arg == "gatehouse" || arg == "structure" ||
     arg == "doorway" || arg == "door") {
    write("The castle is currently under construction.\n");
    return 1;
  }
  write("Enter what?\n");
  return 1;
}
