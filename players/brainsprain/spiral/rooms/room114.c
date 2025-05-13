inherit "room/room";
#include "/players/brainsprain/spiral/spidef.h"
void reset(int arg) {
  
  short_desc = "A roaring waterfall";
  long_desc =
    "A waterfall roars from the heart of the mountain and cascades into the "+
    "corner of this vast underground cavern.  The water rushes into the next "+
    "room.  Two feet of water covers the downward sloped floor.\n";
  set_light(0);
  dest_dir = ({
    sr+"/room113","south",
    sr+"/room115","north",
  });
  items = ({
    "floor",
    "The floor of this cavern",
    "mountain",
    "The mountain that this cavern is carved out of",
    "cavern",
    "The cave you are in",
    "water",
    "Crystal clear mountain water",
    "waterfall",
    "The water pours from a crack in the wall",
    "crack",
    "A huge crack along the northern wall, water rushes out of it",
  });
  clone_list = ({ 1, 1, "slug", sm+"/cub.c", 0,
		  1, 1, "rat", sm+"/rat.c", 0, 
  });
  ::reset(arg);
  replace_program("room/room");
}
