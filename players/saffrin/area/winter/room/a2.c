inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Plateau";
  long_desc =
        "You are on a large, open plateau on top of the mountain.  "+
        "In all directions, the view is amazing.  Far off in the north, "+
        "you can see the Mage Tower, reaching up beyond the "+
        "clouds.  Further south, thick snow covers the plateau with a small path cutting through it.\n";
  smell="The air smells crisp.\n";
  dest_dir=({
        WINT+"room/a1", "north",
        WINT+"room/a3", "south",
  });
  items=({
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

