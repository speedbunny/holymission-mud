inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg) {
  set_light(1);
  short_desc="Stairwell";
  long_desc=
      "You are in a dimly lit stairwell of the Mage Tower.  "+
      "To the north, there is Hafoc Traders, a great place to "+
      "exchange goods.  Laughing is coming from the south where "+
      "Nickum's Tavern is located.  The smell of hops and malt "+
      "brewing is coming from the south at Yilli's World Famous "+
      "Brewery.  There is a doorway to the east with a soft, green "+
      "glow radiating from its frame.  At the center of the "+
      "stairwell, there is a large spiral staircase, leading both"+
      " up and down.\n";
  dest_dir=({
      TOWER+"room/store", "north",
      TOWER+"room/magebar", "south",
      TOWER+"room/oldstart", "east",
      TOWER+"room/kegshop", "west",
      TOWER+"room/hall2", "up",
      TOWER+"quest/c1", "down",
  });
  items=({ 
      "stairwell","A stairwell for a spiral staircase",
      "staircase","A winding spiral staircase",
      "floor","The floor is tiled with dark, green jade",
      "torches", "Brass torches with flicking flames",
      "flames","Flicking orange flames",
  });
  ::reset();
  replace_program("room/room");
}

