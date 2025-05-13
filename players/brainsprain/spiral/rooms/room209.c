inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset( int arg){
  short_desc = "Darkened cavern";
  long_desc =
"As you leave the goblin base camp the cave darkens.  The walls here are "+
"dry as a bone and seem to have melted into place.  What looks like water "+
"on the walls is, in fact, hardened molten stone.  A massive hole in the "+
"wall is so deep that you can not see the end of it.\n";

  set_light(0);
  dest_dir = ({
    sr+"/room208","north",
    sr+"/room210","southeast",
  });
  items = ({
    "walls",
    "The walls appear to be wet but are in fact dry as a bone",
    "hole",
    "A hole about six inches in diameter, it is very deep",
  });
    ::reset(arg);
    replace_program("room/room");
}

