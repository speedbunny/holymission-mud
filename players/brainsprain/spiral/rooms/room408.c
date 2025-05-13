inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset(int arg){
  short_desc = "Stone columns";
  long_desc =
"Rough hewn stone columns line the hallway.  The center of the floor "+
"shows obvious signs of wear.  Loud clicking noises are coming from "+
"the southwest.  A crack runs the length of the northern wall and a "+
"breeze blows through it.\n";
    set_light(0);
    dest_dir = ({
    sr+"/room409","southwest",
    sr+"/room407","east",
  });
items = ({
  "columns",
  "Huge stone columns that appear more ornamental that supportive",
  "floor",
  "The center is worn down from the many hundreds of feet that walk over it",
  "crack",
  "A thin crack in the northern wall",
      });
::reset(arg);
    replace_program("room/room");
}
