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
      "can be heard in the distance.  There are small marble stairs leading up"+
      " from here.  The passage leads towards the north and west.\n";
  dest_dir=({
      HAM+"room/pass13", "west",
      HAM+"room/g1", "up",
  });
  items=({
      "stones", "Cold gray stones making up the entire passage",
      "cobwebs", "Sticky cobwebs, sparkling on the walls and ceiling",
      "stairs", "Small marble stairs",
      "walls#ceiling#ground", "Covered in dust and cobwebs",
      "mortar", "Dirty graying mortar",
  });
  clone_list=({
      1, 1, "rosencrantz", HAM+"npc/rosencra", 0,
      1, 1, "guildenstern", HAM+"npc/guildens", 0,
  });
  ::reset();
  replace_program("room/room");
}
