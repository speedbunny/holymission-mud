inherit "/room/room";

#include "/players/matt/defs.h"

int number;

reset(arg) {
  if(number) number = 0;
  if(arg) return;
  set_light(0);
  short_desc = "Dark Forest";
  long_desc =
    "    The forest remains dark, the trees casting sharp shadows\n" +
    "in all directions. As you look at them, they seem to take on\n" +
    "a form and life of their own.\n" +
    "    But it is just your imagination....\n";

  dest_dir = ({
    NWFORESTA + "rooms/a19", "west",
    NWFORESTA + "rooms/a10", "northeast",
  });

  items = ({
    "trees", "The trees cast strange shadows",
    "forest", "A dark part of the forest",
    "shadows", "Something moves within the shadows",
  });
}

init() {
  ::init();
  add_action("search", "search");
}

search(arg) {
  object lurker;
  if(arg == "shadow" || arg == "shadows") {
    if(number < 10) {
      write("You search the shadows, and something snaps at your hand!\n");
      say(TP->SNAME + " searches the shadows.\n");
      TELLR(ENV(TP), "A foul creature leaps out from the darkness!\n");
      lurker = clone_object(NWFORESTA + "monsters/lurker");
      MOVE(lurker, TO);
      number += 1;
      return 1;
    }
  }
  write("You find nothing special.\n");
  return 1;
}
