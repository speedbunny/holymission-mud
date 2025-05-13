inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Mountain Road";
  long_desc =
    "    The road begins to twist and turn here in order to fit\n" +
    "the terrain, ever sloping up to the north and down to the\n" +
    "south. The wind bites into your flesh, and were you not of\n" +
    "such hardy stock you might suffer physically from the cold.\n" +
    "    Something about the sheer cliff face to the east draws\n" +
    "your attention.\n";

  dest_dir = ({
    NWROAD + "rooms/road18", "northwest",
    NWROAD + "rooms/road16", "south",
  });

  items = ({
    "road", "Here North Road is hewn into the very rock of the mountain",
    "face", "Something looks quite wrong with the cliff face",
    "cliff", "There is definitely something wrong with the cliff",
    "cliff face", "It does not look right",
    "sheer cliff face", "Something about it does not look right",
  });
}

init() {
  ::init();
  add_action("search", "search");
}

search(arg) {
  if(arg == "cliff" || arg == "cliff face" || arg == "face" ||
     arg == "sheer cliff face") {
    write("You run your hands over the rocky face of the eastward cliff\n");
    write("and discover a cleverly hidden man-made passage.\n");
    say(TP->NAME + " searches the eastern cliff and discovers a\n");
    say("cleverly hidden rocky passage.\n");
    add_action("enter", "enter");
    return 1;
  }
  write("You find nothing special.\n");
  return 1;
}

enter(arg) {
  if(arg == "cliff" || arg == "passage") {
    write("You duck into the rocky passage.\n");
    TP->MOVEP("through the eastern cliff face#" +
/* Sauron: 200399: Changed path to point to Redsexy's guild dir.
              NWMOUNT + "rooms/passage01");
*/
              "/players/redsexy/guild/rooms/passage01");
    return 1;
  }
  write("Enter what?\n");
  return 1;
}
