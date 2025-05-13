inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Costume storage";
  long_desc = 
      "You are in the costume storage of the theatre.  This is where the players store "+
      "costumes from the shows they appear in.  There are several wooden racks that "+
      "are filled with costumes hanging along the north wall.  Wooden boxes filled "+
      "shirts and skirts are all over the place.  Along the east wall are several "+
      " shelves pilled high.  They are filled with shoes and boots of all sorts of sizes"+
      " and colors.  A few long planks cover holes in the floor.\n";
  dest_dir=({
      HAM+"room/droom1", "northwest",
  });
  items=({
      "floor", "It is filthy and several holes are covered with planks",
      "planks", "Long wooden planks covering several holes in the floor",
      "shoes#boots", "Of several sizes and colors",
      "racks", "Wooden racks filled with costumes",
      "boxes", "Wooden boxes filled with shirts and skirts",
      "shirts#skirts#costumes", "They appear old and mothy",
      "shelves", "Covered with boots and shoes",
  });
  clone_list=({
      1, 1, "player", HAM+"npc/player", 0,
  });
  ::reset();
  replace_program("room/room");
}
