inherit "/room/room";

#include "/room/room_defs.h"

status move(string str) {
  if(!str)
    str = query_verb();
  switch(str) {
    case "south" :
      write("As you pull at the gate, it opens and you enter the village.\n");
      break;
    case "north" :
      writelw("The heavy rainfall of late has made the road impossible "+
              "to travel.\n");
      return 1;
  }
  return ::move(str);
}

void reset(int arg) {
  set_light(1);
  short_desc="Just outside the northern village gate";
  long_desc=
    "You stand just outside the northern gate into the village. "+
    "The village is surrounded by a wooden stockade to keep any "+
    "dangers out. A road leads north into the wilderness. The "+
    "gate stands a few inches open.\n";

  dest_dir=({
    HM_VILLAGE + "road8", "north",
    HM_VILLAGE + "road6", "south",
  });

  items=({
    "gate","A heavy gate form the northern entrance to the village",
    "stockade","A wooden defense wall, made of sharply pointed poles",
    "village","It's behind the gate",
    "road","Just another dirt road, like so many",
  });

  ::reset(arg);
  replace_program("room/room");
}

