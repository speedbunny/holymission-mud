inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);

  short_desc = "Dressing room";

  long_desc = 
      "You are in one of the dressing rooms of the rundown theatre.  The walls are"+
      "caked with filth.  There are costumes and props of various colors and sizes "+
      "cluttering the floor.  A mirror with candlesticks hanging from it rests against the "+
      " north wall.  There is a half rotted apple sitting on a wooden shelf below the "+
      "mirror.  One lone chair has been placed under the shelf.\n";
  dest_dir=({
      HAM+"room/droom6", "southwest",
  });
  items=({
      "walls", "Flithy walls that are caked with dirt",
      "apple", "A half rotted apple",
      "shelf", "A small wooden shelf",
      "chair", "A small wooden chair",
      "mirror", "AHHH!!!  You see yourself behind the slimey flith",
      "candlesticks", "Small burning candles rest in it",
      "candles" ,"Small white candles that are burning",
      "costumes", "A pile of skirts and capes",
      "props", "A pile of swords, wigs, and candles",
      "floor", "It is cluttered with props and costumes",
  });
  clone_list=({
      1, 8, "player", HAM+"npc/player", 0,
  });
  ::reset();
  replace_program("room/room");
}
