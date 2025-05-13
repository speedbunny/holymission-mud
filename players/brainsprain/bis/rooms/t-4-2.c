inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {
  
  short_desc = "Second floor of northeastern tower";
  long_desc =
    "Various pieces of torture equipment lie about this room.  A rack sits "+
    "in the center of the room.  There are several, large bloodstains spattered "+
    "about the floor.  Perhaps the most terrifying aspect of this room is an "+
    "enormous iron maiden.  A staircase leads up and down.\n";
  set_light(1);
  dest_dir = ({
    br+"/t-4-1.c","down",
    br+"/t-4-3.c","up",
  });
  
  items = ({
    
    "room",
    "Second floor of the northeastern tower",
    "tower",
    "The northeastern tower",
    "equipment",
    "Whips, flails, and chains",
    "rack",
    "A towel rack",
    "bloodstains",
    "Stains of blood",
    "floor",
    "There are several large bloodstains on the floor",
    "iron maiden",
    "There is a funky smelling corpse in it",
    "staircase",
    "Twelve stairs going up and down",
  });
  ::reset(arg);
  replace_program("room/room");

}
