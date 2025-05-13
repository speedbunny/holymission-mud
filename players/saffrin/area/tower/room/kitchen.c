inherit "room/room";

#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc= "Mage Tower Kitchen";
  long_desc =
      "You are in the kitchen of the Mage Tower.  There is a large brick fireplace "+
      "used for cooking in the east wall.  "+
      "A kettle rests over the burning fire, bubbling with stew.  "+
      "In the center of the room is a large preparing table with knives and bowls.  "+
      "Cabinets line the north wall.  Flour, sugar, and salt are in bins "+
      "against the south wall.\n";
  property=({ "has_fire" });
  dest_dir=({
      TOWER+"room/hall8", "east",
  });
  items=({
      "fireplace", "A large fireplace with a crackling fire",
      "bricks", "Dark red bricks making up a fireplace",
      "fire", "A warm, crackling fire giving off a glow",
      "glow", "A soft glow from the fire",
      "spoon", "Used to 'taste' the stew",
      "kettle", "A large black kettle with stew in it and a spoon",
      "stew", "Delious stew",
      "table", "A large table for preparing food",
      "knives", "Knives used for cutting food",
      "bowls", "Bowls used to hlep prepare food",
      "cabinets", "Filled with dishes and mugs",
      "dishes", "The dishes thate mages eat of",
      "mugs", "The mugs that amges drink out of"
      "four", "Flour to b used in cooking",
      "sugar", "Sugar to be used in cooking",
      "salt", "Salt to be used in cooking",
      "bins", "Large wooden bins for storage",
  });
  ::reset();
  replace_program("room/room");
}
