inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Prop room";
  long_desc = 
      "You are in the prop room of the theatre.  This is where the players store "+
      "props from the shows they appear in.  There are several wooden flats with "+
      "paint chipping off them along the north wall.  A small wooden bed is in the "+
      "middle of the room with dust covering it.  Along the east wall are several "+
      " shelves pilled high.  They are filled with utensils of all sorts of shapes and "+
      "colors.  A few long planks cover holes in the floor.\n";
  dest_dir=({
      HAM+"room/droom1", "southwest",
  });
  items=({
      "floor", "It is filthy and several holes are covered with planks",
      "planks", "Long wooden planks covering several holes in the floor",
      "utensils", "Utensils of several shapes and colors",
      "flats", "Wooden flats with paint chipping off of them",
      "bed", "A dusty wooden bed that appears to be moldy",
      "paint", "Chipping off the flats",
      "shelves", "Covered with utensils",
  });
  clone_list=({
      1, 3, "player", HAM+"npc/player", 0,
  });
  ::reset();
  replace_program("room/room");
}
