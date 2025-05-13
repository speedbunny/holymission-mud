inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "The ballroom";
  long_desc = 
      "You are in part of the gloriously beautiful ballroom of the castle of Denmark.  "+
      "The high ceiling is covered in hand painted cherubs and faeries, glittering with"+
      "gold trim.  The floor is made from fine marble imported from Botswana, speckling white "+
      "with black.  It shines brightly from being newly polished and waxed.  "+
      "Several chandliers filled with candles hang down from the ceiling above.\n";
  dest_dir=({
      HAM+"room/throne1", "north",
      HAM+"room/throne3", "south",
      HAM+"room/throne5", "west",
  });
  items=({
      "chandliers", "Filled with candles",
      "ceiling", "Painted with cherubs and faeries",
      "cherubs","Small baby angelic cherubs",
      "faeries", "Shimmery faeries",
      "candles", "Candles lighting the room",
      "marble", "Marble imported from Botswana.  It is speckled black and white",
      "floor", "All marble",
      "trim", "Gold trim on the ceiling",
  });
  clone_list=({
      1, 1, "horatio", HAM+"npc/horatio", 0,
  });
  ::reset();
  replace_program("room/room");
}
