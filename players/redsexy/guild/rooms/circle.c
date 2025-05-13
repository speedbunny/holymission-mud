inherit "/room/room";

#include "/players/redsexy/guild/guilddefs.h"

object chest;

reset(arg) {
  if(arg) return;
  set_light(0);
  short_desc = "Mountain Circle";
  long_desc =
    "    You stand in a circle near the summit of the mountain.\n" +
    "A perpetual night darkens your surroundings, and something\n" +
    "about the strength and fury of the wind suggests that there\n" +
    "is a mighty force nearby.\n" +
    "    In the center of the circle stands a square building\n" +
    "made of black stone. No light shines from within.\n";
  no_obvious_msg = "";
  
  dest_dir = ({
    "players/redsexy/guild/rooms/passage04", "down",
  });

  items = ({
    "circle", "A circle of stone at the top of this mountain",
    "summit", "You stand on the summit of one of the higher peaks",
    "mountain", "You are very high up in the mountains",
    "building", "There is an open doorway set into the building",
    "stone", "Black stones that make up the building's exterior",
    "doorway", "A doorway into the dark building"
  });
}

init() {
  ::init();
  add_action("enter", "enter");
} 

enter(arg) {
  if(arg == "doorway" || arg == "building") {
    write("You enter the doorway.\n");
    TP->MOVEP("through the doorway#" + PATH + "/rooms/anteroom");
    return 1;
  }
  write("Enter what?\n");
  return 1;
}
