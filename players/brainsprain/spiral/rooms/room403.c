inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "Meeting place of the goblin mystics";
  long_desc =
"This room is filled with pieces of goblin arcana.  The tails of rats hang "+
"from the walls and a cauldron sits boiling in the center of the room "+
"Around the cauldron is a row of chairs, looks like there is going to "+
"be a meeting.\n";
    set_light(0);
    dest_dir = ({
    sr+"/room402","southwest",
    sr+"/room404","northeast",
  });
  items = ({
   "tails",
   "Rotting rat tails adorn the wall",
   "cauldron",
   "A massive iron pot",
   "chairs",
   "Old wooden chairs fornly bolted to the ground",
 });
    clone_list = ({ 
       1, 1, "monster", sm+"/goblin_mystic.c", 0,
    });   
  ::reset(arg);
    replace_program("room/room");
}
