inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Mage Tower Gardens";
  long_desc =
       "You are in the beautiful garden of the Mage Tower.  A large ivy doorway "+
       "is to the south.  Several flower patches of tulips and daisies are along the "+
       "north quartz wall.  Rose bushes line the northeast and northwest corners.  "+
       "The walls are made from clear quartz panels, allowing light to set in the "+
       "garden.  The garden continues to the southeast and southwest.\n";
  dest_dir=({
      TOWER+"room/hall9", "south",
      TOWER+"room/garden4", "southeast",
      TOWER+"room/garden2", "southwest",
  });
  items=({
      "garden", "A beautiful garden filled with flowers",
      "flowers", "Roses, tulips, and daisies",
      "patches", "Patches of tulips and daisies",
      "bushes", "Bushes of roses",
      "walls", "Walls made from clear quartz",
      "panels", "Panels made from clear quartz",
      "quartz", "Clear quartz",
      "light", "Light coming from the panels",
      "roses", "Beautiful roses",
      "tulips", "Beautiful tulips",
      "daisies", "Beasutiful daisies",
      "doorway", "A doorway made from ivy",
      "ivy", "Ivy making up a doorway",
  });
  smell="You smell flowers all around you.";
  clone_list =({
      1, 2, "fairy", TOWER+"npc/fairy", 0,
  });
  ::reset();
  replace_program("room/room");
}
