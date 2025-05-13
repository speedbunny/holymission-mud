inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  long_desc =
"A set of stairs lead up. The floor shows the sign of wear.  Multitudes "+
"of four-toed footprints cover the floor.  Several boot marks are "+
"intermingled in the dust.  An un-natural fog clings to the walls.\n";
   set_light(0);
    dest_dir = ({
    sr+"/room610","up",
    sr+"/room702","west",
  });
  items =({
    "boot marks",
    "Prints left in the dust by a set of large boots",
    "footprints",
    "Orcish footprints",
  });
::reset(arg);
    replace_program("room/room");
}
