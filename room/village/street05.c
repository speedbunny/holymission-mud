inherit "/room/room";

#include "/room/room_defs.h"

void reset(int arg) {
  set_light(1);
  short_desc = "The northern corner of Main Street";
  long_desc =
    "You've arrived at the northern corner of Main Street. To the "+
    "east lies the village square. Main Street curves south here. "+
    "just outside the curve lie a few piles of logs, waiting "+
    "to be worked up, or to be sold.\n";

  dest_dir = ({
    HM_VILLAGE + "square2", "east",
    VILLAGE_MEET + "meeting_hall", "west",
    HM_VILLAGE + "street06", "south"
  });

  items = ({
    "main street","The major road through the village",
    "square","A cobblestone square forms the place where things "+
      "happen in this village",
    "village square","A cobblestone square forms the place where "+
      "things happen in this village",
    "corner","You can see obviously from the tracks here that this "+
      "road is used often",
    "curve","The road curves from east to south here",
    "tracks","Tracks from people's feet, horses' hooves and wagon's wheels",
    "piles","Neatly stacked piles of logs",
    "logs","Woodcutters have brought them from the forest",
  });

  ::reset(arg);
  replace_program("room/room");
}

