inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Bend";
  long_desc =
    "    Here the road bends. To the northeast it runs into a grassy\n" +
    "plain, and to the south you can see the Archway. The forest on\n" +
    "either side of you is fairly dense, and the mountains loom over\n" +
    "you to the north.\n";

  dest_dir = ({
    NWROAD + "rooms/road05", "northeast",
    NWROAD + "rooms/road03", "south",
  });
  
  items = ({
    "trees", "They are packed closely together",
    "road", "The road bends here, going northwest and south",  
    "mountains", "Huge peaks reaching towards the sky",
    "forest", "The forest is dark and forbidding",
    "plain", "You see a wide grass-covered plain stretching before you",
    "archway", "You can make out the Archway to the south",
  });
}

init() {
  ::init();
  add_action("no_way", "west");
  add_action("no_way", "east");
}
        
no_way() {
  write("The forest is too thick here.\n");
  return 1;
}
