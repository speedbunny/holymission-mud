inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Clearing";
  long_desc =
    "    This is a clearing of sorts, a corner of the forest that\n" +
    "feels very peaceful and quiet. There are no trees here, save\n" +
    "the ones that surround this place, though a squat tree stump\n" +
    "sits amid a clump of thick green grass.\n";

  dest_dir = ({
    NWFORESTB + "rooms/b07", "east",
    NWFORESTB + "rooms/b02", "north",
  });

  items = ({
    "clearing", "A tranquil forest clearing",
    "trees", "Tall trees surrounding you",
    "clump", "A thick clump of overgrown grass",
    "grass", "Green and tall, the grass grows in small patches here",
    "stump", "The remains of a huge tree. You notice something on it",
    "tree stump", "A short, squat tree stump",
    "writing", "Writing on the tree stump",
  });
}

init() {
  ::init();
  add_action("search", "search");
  add_action("read", "read");
}

search(arg) {
  if(arg == "stump" || arg == "tree stump") {
    write("You notice writing carved into the tree stump.\n");
    return 1;
  }
  write("You find nothing special.\n");
  return 1;
}

read(arg) {
  object spec;
  if(arg == "writing" || arg == "stump" ||
     arg == "tree stump") {
    spec = present("spectacles", TP);
    if(spec && spec->query_worn()) {
      write("It is just one word: 'Gaiea'.\n");
      spec->set_reader(TP->RNAME);
      return 1;
    }
    write("The writing is in some language that you don't recognize.\n");
    return 1;
  }
}
