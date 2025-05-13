inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Make up room";
  long_desc = 
      "You are in the make up room of the theatre.  This is where the players prepare "+
      "themselves for each performance they appear in.  There is a long shelf along "+
      "the south wall with small bottles and jars on top of it.  A mirror is above the shelf "+
      "with several candles surrounding its edges.  Along the east wall are several "+
      " shelves pilled high.  They are filled with wigs of all sorts of length and "+
      "colors.  A few long planks cover holes in the floor.\n";
  dest_dir=({
      HAM+"room/droom9", "northwest",
  });
  items=({
      "floor", "It is filthy and several holes are covered with planks",
      "planks", "Long wooden planks covering several holes in the floor",
      "wigs", "Wigs of several lengths and colors",
      "mirror", "AHHHH!!!  You see yourself",
      "candles", "Burning candles to light the room",
      "bottles#jars", "Filled with stage make up",
      "shelves", "Covered with bottles, jars, and wigs",
  });
  ::reset();
  replace_program("room/room");
}
