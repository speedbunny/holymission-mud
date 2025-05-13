inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"
void reset(int arg) {

  short_desc = "A palely illuminated room.";
  long_desc =
    "This room is well lit by a torch.  The floor here is bare, there isn't "+
    "even any dust on it.  Small ridges have formed in the floor as if water "+
    "used to flow across it "+
    "The walls and ceiling are dry and completely smooth.\n";
  set_light(1);
  items = ({
    "ridges",
    "Small granite ridges where weaker rock has been washed away",
    "walls",
    "They are dry and completely smooth",
    "ceiling",
    "It is dry and completely smooth",
    "room",
    "Part of an underground cavern",
    "torch",
    "a torch, it is bolted to the wall",
  });
  dest_dir = ({
    sr+"/room110","west",
    sr+"/room112","northeast",
  });
  ::reset(arg);
  replace_program("room/room");
}

