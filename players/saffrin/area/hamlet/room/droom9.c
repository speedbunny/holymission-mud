inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Backstage hall";
  long_desc = 
      "You are walking along the hallway in the backstage of the theatre,"+
      "which leads to various rooms.  The make up room is located to the southeast.  "+
      "There are several candles hanging "+
      "off the walls to light your way.  The hall is not kept very clean."+
      "  There are costumes and props all over the place and the floor looks like it has "+
      "not been cleaned in ages.  A few long planks cover holes in the floor.\n";
  dest_dir=({
      HAM+"room/droom11", "east",
      HAM+"room/droom6", "west",
      HAM+"room/droom12", "southeast",
  });
  items=({
      "floor", "It is filthy and several holes are covered with planks",
      "candles", "Hanging off the walls to light your way",
      "walls", "Candles are hanging off them",
      "planks", "Several wooden planks covering several holes in the floor",
      "costumes", "A pile of skirts and capes",
      "props", "A pile of swords, wigs, and candles",
  });
  ::reset();
  replace_program("room/room");;
}
