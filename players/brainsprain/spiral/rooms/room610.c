inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "Stairwell";
  long_desc =
"A set of stairs sits along the northern wall going down.  Other "+
"than that the room is absolutely barren.  The walls and floor are "+
"completely devoid of dust.  The sounds of metal hitting metal come "+
"from the southeast.\n";
    set_light(0);
   items = ({
     "stairs","They lead down to the next level of the cavern",
     "walls","Completely devoid of dust",
     "floor","The floor is completely barren",
     }); 
   dest_dir = ({
    sr+"/room609","southeast",
    sr+"/room701","down",
  });
  ::reset(arg);
    replace_program("room/room");
}
