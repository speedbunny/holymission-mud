inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "Hallway of guttering torches";
  long_desc =
"Every five feet along the walls a torch is firmly bolted to the wall.  "+
"The guttering flames throw strange shadows along the walls.  Several.  "+
"torches have blown out and someone should be along to change them soon.\n";
   set_light(1);
    dest_dir = ({
    sr+"/room503","southwest",
    sr+"/room505","northeast",
  });
  items =({
    "torches",
    "long burning torches",
    "flames"
    "The flames bob and weave like a boxer",
  });
  ::reset(arg);
    replace_program("room/room");
}
