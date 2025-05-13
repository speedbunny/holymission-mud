inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "A stairwell";
  long_desc =
"A set of stairs winds up to the next level of the caverns. The sound of "+
"something shuffling about can easily be heard coming from the next room. "+
"The walls are covered with condensation that gleams in your torch light.\n";
    set_light(0);
    items = ({
     "stairs","A set of stairs leading up to the next level",
     "caverns","These are the caves that you are in",
     "walls","They are covered in condensation",
   });
    dest_dir = ({
    sr+"/room412","up",
    sr+"/room502","southeast",
  });
  ::reset(arg);
    replace_program("room/room");
}
