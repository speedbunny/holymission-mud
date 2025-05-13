inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Mage Tower Dining Hall";
  long_desc =
      "You are in the dining hall of the Mage Tower.  There is a large table "+
      "in the center of the room with several chairs placed around it.  "+
      "Mugs and plates are set before each chair.  Hanging from the ceiling is "+
      "a large chandelier filled with candles.  "+
      "Torches are along the walls, adding light to the room.\n";
  property=({ "has_fire" });
  dest_dir=({
      TOWER+"room/hall8", "south",
  });
  items=({
      "chandelier", "Large chandelier filled with unlit candles",
      "candles", "White unlit candles",
      "torches", "Several torches lit for light",
      "walls", "There are torches hanging off them",
      "table", "A large table the mages eat around",
      "chairs", "Several chairs for the mages to sit on",
      "mugs", "Mugs of ale",
      "plates", "Plates for the mage food",
  });
  ::reset();
  replace_program("room/room");
}
