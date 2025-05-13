inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "Orc Pantry";
  long_desc =
"Kegs of long soured ale and tubs of rancid lard sit on shelves here.  "+
"A steady humming sound comes from the southeast.  A sack sits in the.  "+
"corner of the room and twitches.  The smell of rotting food is heavy "+
"in the air.\n";
   set_light(0);
    dest_dir = ({
    sr+"/room603","southeast",
    sr+"/room601","north",
  });
  items =({
    "kegs",
    "Kegs of sour ale",
    "tub",
    "A tub of rancid lard",
    "sack",
    "A sack of live rats",
  });
  ::reset(arg);
    replace_program("room/room");
}
