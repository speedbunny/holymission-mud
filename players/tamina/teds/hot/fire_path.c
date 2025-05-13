inherit "room/room";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
    if(arg) return 0;
    set_light(1);
    short_desc = "Very Hot Path";
    long_desc =
"The smell of sulfer and burning fills the air.\n"+
"To the south can be seen a large pool of lava.\n"+
"While strange tree like shapes lie to the north.\n"+
"Far to the east can be seen, through the haze and\n"+
"smoke, a large smoking volcano.\n";
 
   dest_dir = ({
  THOT + "fire_forest", "north",
  THOT + "fire_south", "south",
  THOT + "hot_path", "west",
  THOT + "fire_path2", "east"
     });

   ::reset();
   replace_program("room/room");
}
