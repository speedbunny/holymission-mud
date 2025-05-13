inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Plateau";
  long_desc =
        "You are on a large, open plateau on the top of the mountain "+
        "with a small path begining to cut into the south in the snow.  "+
        "In all directions, the view is amazing.  The path appears "+
        "to lead into a park in the southern part of the mountain.\n";
  smell="The air smells crisp.\n";
  dest_dir=({
        WINT+"room/a2", "north",
        WINT+"room/p1", "south",
  });
  items=({
        "park", "A park to the south",
        "plateau", "A snow covered plateau",
        "snow", "Thick, white snow.",
        "mountain", "A snow covered mountain",
        "top", "The top of the mountain",
        "path", "A small path cutting through the plateau",
        "view", "An amazing view in all directions",
        "distance", "A place to the north",
        "tower", "The Mage Tower",
        "clouds", "White, fluffy clouds",
  });
  ::reset();
  replace_program("room/room");
}

