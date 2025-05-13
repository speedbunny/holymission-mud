inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Backstage hall";
  long_desc = 
      "You are walking along the hallway in the backstage of the theatre,"+
      "which leads to various rooms.  The players' dressing rooms lead to the northeast"+
      " and to the southeast.  There are several candles hanging "+
      "off the walls to light your way.  The hall is not kept very clean."+
      "  There are costumes and props all over the place and the floor looks like it has "+
      "not been cleaned in ages.  A few long planks cover holes in the floor.\n";
  dest_dir=({
      HAM+"room/droom9", "east",
      HAM+"room/droom3", "west",
      HAM+"room/droom8", "northeast",
      HAM+"room/droom10", "southeast",
  });
  items=({
      "candles", "Candles hanging off the walls to light your way",
      "walls", "Candles are hanging off of them",
      "floor", "It is filthy and several holes are covered with planks",
      "planks", "Long wooden planks covering several holes in the floor",
      "costumes", "A pile of skirts and capes",
      "props", "A pile of swords, wigs, and candles",
  });
  clone_list=({
      1, 4, "player", HAM+"npc/player", 0,
  });
  ::reset();
  replace_program("room/room");
}
