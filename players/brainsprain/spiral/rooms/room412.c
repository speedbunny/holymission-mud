inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "Goblin Throne Room";
  long_desc =
"Old tapestries hang on the walls here.  A huge throne sits against the "+
"southern wall.  A set of stairs sits along the western wall.  The king "+
"does not appear to be here at the moment though.\n";
    set_light(1);
    dest_dir = ({
    sr+"/room411","northwest",
    sr+"/room501","down",
  });
items = ({
  "tapestry",
  "A tapestry depicting the death of a dwarf at the hands of a goblin",
  "throne",
  "A massive throne made of the bones of animals",
        });
    clone_list = ({ 
       1, 1, "fighter", sm+"/human_fighter.c", 0,
        });   
  ::reset(arg);
}

