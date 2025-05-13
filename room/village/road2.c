inherit "/room/room";

#include "/room/room_defs.h"

status move(string str) {
  if(!str)
    str = query_verb();
  if(str == "north") {
    write("The bank is not yet open.\n");
    return 1;
  }
  return ::move(str);
}

void reset(int arg) {
  set_light(1);
  short_desc = "The eastern corner of Rich Men's Road";
  long_desc =
    "You are at the eastern corner of Rich Men's Road. Here the "+
    "road changes from the dirt road from the south into a paved "+
    "road leading west. To the north lies a stone building.\n";

  dest_dir = ({
    HM_VILLAGE + "newbroker", "north",
    HM_VILLAGE + "road3", "west",
    HM_VILLAGE + "road1", "south",
  });

  items = ({
    "corner","From here the road turns leads south and west",
    "rich men's road","A paved road through the rich part of the "+
      "village",
    "road","The road is made of red bricks, but covered with much "+
      "sand from the south",
    "bricks","Red bricks are form a well layed roadsurface",
    "building","A building of yellow bricks. A sign on it reads: "+
      "Forest Investers Coop., Bank",
  });

  ::reset(arg);
  replace_program("room/room");
}

