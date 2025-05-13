inherit "/room/room";

#include "/room/room_defs.h"

status move(string str) {
  if(!str)
    str = query_verb();
  if(str == "north")
    writelw("You open the gate and leave the village. The gate "+
            "closes again behind you.\n");
  return ::move(str);
}

void reset(int arg) {
  set_light(1);
  short_desc="Behind the northern village gate";
  long_desc=
    "You stand right behind the northern village gate. Rich "+
    "Men's Road runs south from here. A small guard booth "+
    "stands next to the gate. Another road runs north from "+
    "here into the wilderness.\n";

  dest_dir=({
    HM_VILLAGE + "road7", "north",
    HM_VILLAGE + "road5", "south",
  });

  items=({
    "gate","A heavy gate in the wooden stockade that surrounds "+
      "the village",
    "stockade","A defense wall made of sharply pointed poles",
    "rich men's road","A brick road, leading through the richer "+
      "part of the village",
    "road","It's made of red bricks",
    "bricks","Red bricks",
    "booth","A shelter for the guard on duty. Right now it's empty",
  });

  ::reset(arg);
  replace_program("room/room");
}

