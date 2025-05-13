
inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"
void reset(int arg) {

  short_desc = "Sloping floor";
  long_desc =
    "The gradual downward slope of the floor indicates that you are moving "+
    "further into the heart of the mountain.  A massive cocoon of some "+
    "creature hangs from the ceiling.  The amount of dust on the floor "+
    "has noticeably decreased.\n";
  set_light(0);
  items = ({
    "ceiling",
    "The ceiling of the cavern",
    "dust",
    "There is a light layer of yellow dust",
    "floor",
    "There is a noticeable downward slope to the floor",
    "cocoon",
    "A green cocoon of some large creature",
  });
  dest_dir = ({
    sr+"/room105","north",
    sr+"/room107","south",
  });
  ::reset(arg);
  replace_program("room/room");
}
