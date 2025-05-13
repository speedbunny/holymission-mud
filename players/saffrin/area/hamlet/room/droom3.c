inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Backstage hall";
  long_desc = 
      "You are walking along the hallway in the backstage of the theatre,"+
      " which leads to various rooms.  The prop shop leads off to the northeast "+
      " and to the southeast is the costume shop.  There are several candles along "+
      "the walls to light your way.  The hall is not kept very clean."+
      "  There are costumes and props all over the place and the floor looks like it has "+
      "not been cleaned in ages.  A few long planks cover holes in the floor.\n";
  dest_dir=({
      HAM+"room/droom6", "east",
      HAM+"room/droom1", "west",
      HAM+"room/droom5", "northeast",
      HAM+"room/droom7", "southeast",
  });
  items=({
      "floor", "It is filthy and several holes are covered with planks",
      "planks", "Long wooden planks covering several holes in the floor",
      "candles", "Hanging off the walls to light your way",
      "walls", "Candles are hanging off them",
      "costumes", "A pile of skirts and capes",
      "props", "A pile of swords, wigs, and candles",
  });
  ::reset();
  replace_program("room/room");
}
