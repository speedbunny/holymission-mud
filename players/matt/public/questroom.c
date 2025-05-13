inherit "/room/room";

#include "/players/matt/defs.h"

void reset(int arg) {
  if(!present("questboard", TO)) MOVE(CLONE(PATH + "public/questboard"), TO);
  if(arg) return;
  set_light(1);
  short_desc = "Quest discussion room";
  long_desc =
    "    This room is for discussing the quest system, including new\n" +
    "ideas and storylines and opinions on existing quests. Please post\n" +
    "your comments!\n";
}

