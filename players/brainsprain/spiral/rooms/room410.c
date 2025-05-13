inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "Slotted Walls";
  long_desc =
"Slots line the walls here, about one foot away from each other.  A "+
"clicking noise is coming out of them.  It sounds as if though millions "+
"of beetles are within the walls.  A pinion hangs on the western wall.\n";
    set_light(0);
    dest_dir = ({
    sr+"/room411","south",
    sr+"/room409","northeast",
  });
items = ({
  "pinion",
  "A yellow pinion bearing the insignia of Galgug",
  "slots",
  "Each it covered in glass, behind which you can see an ant farm",
        });
  ::reset(arg);
    replace_program("room/room");
}
