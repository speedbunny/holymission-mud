inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Prop shop";
  long_desc = 
      "You are in the prop shop of the theatre.  This is where the players make "+
      "props from the shows they appear in.  There are several wooden flats that "+
      "have been painted black along the north wall.  A small wooden work bench"+
      "is in the middle of the room.  Along the east wall are several "+
      " shelves pilled high.  They are filled with jars and tools of all sorts of sizes.  "+
      "A few long planks cover holes in the floor.\n";
  dest_dir=({
      HAM+"room/droom3", "southwest",
  });
  items=({
      "floor", "It is filthy and several holes are covered with planks",
      "planks", "Long wooden planks covering several holes in the floor",
      "jars#tools", "Jars and tools of several sizes", 
      "flats", "Wooden flats painted black",
      "bench", "A wooden bench with sawdust on it",
      "paint", "Black paint",
      "shelves", "Covered with jars and tools",
      "sawdust", "Dust from the wood",
  });
  ::reset();
  replace_program("room/room");
}
