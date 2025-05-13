inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Backstage hall";
  long_desc = 
      "You are in the entrance hall to the backstage of the theatre"+
      " and its various dressing rooms.  The prop room leads off to"+
      " the northeast and to the southeast is the costume storage.  "+
      "There are large doors leading out of the theatre to the west."+
      "  The hall is not kept very clean.  There are costumes and props"+
      " all over the place and the floor looks like it has not been "+
      "cleaned in ages.  A few long planks cover holes in the floor.\n";
  dest_dir=({
      HAM+"room/droom3", "east",
      HAM+"room/droom2", "northeast",
      HAM+"room/droom4", "southeast",
      HAM+"room/enter", "out",
  });
  items=({
      "floor", "It is filthy and several holes are covered with planks",
      "planks", "Long wooden planks covering several holes in the floor",
      "door", "A wooden door cracked around the corners",
      "costumes", "A pile of skirts and capes",
      "props", "A pile of swords, wigs, and candles",
  });
  ::reset();
  replace_program("room/room");
}
