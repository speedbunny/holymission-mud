inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(0);
  short_desc = "A dark passage";
  long_desc = 
      "You are walking in a dark and narrow passage made from cold gray stones.  "+
      "The stones are in various sizes and are held in place by dirtied mortar. "+
      "Cobwebs line some of the edges where the ceiling meets the walls, in a white,"+
      " sparkling display.  Dust covers the walls, ceiling, and ground.  A low howling "+
      "can be heard in the distance.  "+
      "The passage leads towards the north.\n";
  dest_dir=({
      HAM+"room/pass8", "north",
  });
  items=({
      "stones", "Cold gray stones making up the entire passage",
      "cobwebs", "Sticky cobwebs, sparkling on the walls and ceiling",
      "walls#ceiling#ground", "Covered in dust and cobwebs",
      "mortar", "Dirty graying mortar",
  });
  clone_list=({
      1, 3, "guard", HAM+"npc/dguard", 0,
  });
  ::reset();
  replace_program("room/room");
}
