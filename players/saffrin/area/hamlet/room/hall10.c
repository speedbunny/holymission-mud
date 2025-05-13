inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "The castle kitchens";
  long_desc = 
      "You are in the hot and stuffy kitchens for the castle of Denmark's cooking.  "+
      "Along the west wall is a large fireplace made completely from red brick.  There "+
      "are two half round holes on either side of the main fire.  The fire is burning bright "+
      "with small sparks crackling from it.  A large table is in the middle of the room for the "+
      "preparations of the meals.\n";
  dest_dir=({
      HAM+"room/hall8", "north",
      HAM+"room/hall9", "southwest",
  });
  items=({
      "table", "A large table for meal preparations",
      "fireplace", "A large brick fireplace",
      "fire","An orange crackling fire",
      "spark", "Small orange sparks",
      "holes", "Holes that are round on the top and flat on the bottom from baking",
      "brick#bricks", "Red bricks",
  });
  ::reset();
  replace_program("room/room");
}
