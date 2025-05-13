inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Plateau";
  long_desc =
        "You are on a large, open plateau on top of the mountain.  "+
        "In all directions, the view is amazing.  In the northern distance, "+
        "you can see the Mage Tower, reaching up beyond the "+
        "clouds.  Further south, thick snow covers the plateau.\n";
  smell="The air smells crisp.\n";
  dest_dir=({
        "/room/mount_top2", "north",
        WINT+"room/a2", "south",
  });
  items=({
        "plateau", "A snow covered plateau",
        "snow", "Thick, white snow.",
        "mountain", "A snow covered mountain",
        "top", "The top of the mountain",
        "view", "An amazing view in all directions",
        "distance", "A place to the north",
        "tower", "The Mage Tower",
        "clouds", "White, fluffy clouds",
  });
  ::reset();
  replace_program("room/room");
}

