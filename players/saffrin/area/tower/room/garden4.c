inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Mage Tower Gardens";
  long_desc =
       "You are in the beautiful garden of the Mage Tower.  "+
       "Several flower patches of tulips and daisies are along the "+
       "east quartz wall.  Rose bushes line the northeast and southeast corners.  "+
       "The walls are made from clear quartz panels, allowing light to set in the "+
       "garden.  The garden continues to the northwest and southwest.\n";
  dest_dir=({
      TOWER+"room/garden1", "northwest",
      TOWER+"room/garden3", "southwest",
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
  clone_list = ({
      1, 1, "fairy", TOWER+"npc/fairy", 0,
  });
  ::reset();
  replace_program("room/room");
}
