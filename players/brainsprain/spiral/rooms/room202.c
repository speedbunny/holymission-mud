inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"

void reset( int arg){
 short_desc = "The fungus room";
  long_desc =
"A pale blue fungus covers whole sections of the walls here.  The uncovered "+
"sections of the wall are made of a composite of soapstone and granite. "+
"The mainly soapstone floor is very slippery from the mist that has settled "+
"on it.\n";
  set_light(0);
  dest_dir = ({
    sr+"/room201","southeast",
    sr+"/room203","northwest",
  });
  items = ({
    "walls",
    "The walls are covered in a blue fungus",
    "moisture",
    "The moisture has condensed on the ceiling and walls and drips to the floor",
    "fungus",
    "A blue fungus, it smells awful",
    "floor",
    "The moisture from the waterfall has condensed on the floor",
  });
    clone_list = ({ 1, 1, "monster", sm+"/goblin.c", 0 });   
    ::reset(arg);
    replace_program("room/room");
}
