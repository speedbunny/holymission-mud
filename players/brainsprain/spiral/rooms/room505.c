inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "Hallway of guttering torches";
  long_desc =
"Every five feet along the walls a torch is firmly bolted to the wall.  "+
"The guttering flames throw strange shadows along the walls.  Most of "+
"the torches have blown out.  Shards of wood are piled on the floor "+
"under each torch.\n";
   set_light(1);
    dest_dir = ({
    sr+"/room506","north",
    sr+"/room504","southwest",
  });
  items =({
    "torches",
    "long burning torches",
    "flames"
    "The flames bob and weave like a boxer",
    "shards",
    "The remains of old torches, broken after they are used up",
  });
    clone_list = ({ 
       1, 1, "monster", sm+"/orc_guard.c", 0,
        });
  ::reset(arg);
    replace_program("room/room");
 }
