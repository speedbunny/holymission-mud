inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "The throne";
  long_desc = 
      "You are on the throne of the king and queen of the castle of Denmark.  "+
      "The high ceiling is covered in hand painted cherubs and faeries, glittering with"+
      "gold trim.  The floor is made from fine marble imported from Botswana, speckling white "+
      "with black.  It shines brightly from being newly polished and waxed.  "+
      "Several chandliers filled with candles hang down from the ceiling above.  "
      "There are two high backed chairs lined with red velvet along the west wall.  "
      "There is a doorway to the southwest.\n";
  dest_dir=({
      HAM+"room/throne14", "north",
      HAM+"room/throne12", "east",
      HAM+"room/sideroom", "southwest",
  });
  items=({
      "chairs", "High backed chairs lined with red velvet",
      "velvet", "Dark red velvet",
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
      1, 1, "gertrude", HAM+"npc/gertrude", 0,
      1, 1, "claudius", HAM+"npc/claudius", 0,
  });
  ::reset();
  replace_program("room/room");
}
