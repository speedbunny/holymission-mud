inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc="The village square";
  long_desc=
    "You've arrived at the village square. Main street continues "+
    "both east and west from here.  To the south some bushes secure "+
    "the peace of the churchyard. North of the square stands "+
    "'The Thirsty Treant' pub.\n";

  dest_dir=({
    HM_VILLAGE + "pub", "north",
    HM_VILLAGE + "street04", "east",
    HM_VILLAGE + "square2", "west"
  });

  items=({
    "village square","A wide cobblestone square",
    "square","A wide cobblestone square",
    "main street","A well maintained dirt road, running east-west "+
      "through the village",
    "street","A well maintained dirt road, running east-west "+
      "through the village",
    "bushes","A thornhedge surrounds the churchyard. There are some "+
      "holes in it",
    "holes","Small holes in the thornhedge you can peek through",
    "pub","There seems to a lot enjoyment inside",
  });
  ::reset(arg);
}

void init() {
  ::init();
  add_action("_peek","peek");
}

/* take a look at the churchyard */
status _peek(string str) {
  switch(str) {
    case "through holes" :
    case "holes" :
      writelw("Through the little hole you catch a glimpse of the "+
              "churchyard. A small gravel path runs between ancient "+
              "tombes. A bunch of fresh flowers stands at the foot "+
              "of each tomb. Some person is busy doing something "+
              "between the tombs, but you can't get a better look at "+
              "it from here. As you stand up again, you notice some "+
              "people speaking shame of you. \n");
      say(lw(TP->NAME + " peeks shamelessly through the hedge of the "+
             "churchyard.\n"));
      return 1;
    default :
      notify_fail("Peek what?\n");
      return 0;
  }
}

