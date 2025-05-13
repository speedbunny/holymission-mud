inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "Hallway of guttering torches";
  long_desc =
"Every five feet along the walls a torch is firmly bolted to the wall.  "+
"The guttering flames throw strange shadows along the walls.  Mats cover "+
"the western side of the floor.  The scent of kerosene is strong in the "+
"air.\n";
   set_light(1);
    dest_dir = ({
    sr+"/room502","west",
    sr+"/room504","northeast",
  });
  items =({
    "torches",
    "long burning torches",
    "flames"
    "The flames bob and weave like a boxer",
    "shadows",
    "anything could be hiding here....",
  });
  ::reset(arg);
    replace_program("room/room");
}
