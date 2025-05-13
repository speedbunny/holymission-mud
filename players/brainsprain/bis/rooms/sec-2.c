inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {

  short_desc = "A room on the second floor";
  long_desc =
"This room looks a lot like all the other rooms on this floor.  The walls "+
"are made of a monotonous gray stone and the floors are all covered in "+
"old green rugs.  It could be very easy to get lost in this section.\n";
  set_light(1);
  items = ({
    "room",
    "A room on the second floor",
    "stone",
    "Large stones that have been crafted to make walls",
    "walls",
    "Monotonous gray walls",
    "floors",
    "The floor looks like the floor in all the other rooms",
    "rugs",
    "Puce green rugs",
  });
  dest_dir = ({
    br+"/sec-1.c","north",
    br+"/sec-1.c","south",
    br+"/sec-3.c","west",
    br+"/sec-2.c","east",
    br+"/t-3-2.c","leave",
  });
  ::reset(arg);
  replace_program("room/room");

}

