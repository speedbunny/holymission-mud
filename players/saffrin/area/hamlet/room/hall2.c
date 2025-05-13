inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "The castle hallway";
  long_desc = 
      "You are in the decorative and glorious hallway of the castle of Denmark.  "+
      "The walls are lined with red velvet and trimmed with golden rope tassels. "+
      "The ceiling is covered with a hand woven tapestry, draping lightly down from "+
      "the center of the piece.  The floor is carpeted with a fine Maltese styled rug, "+
      "stringing red, gold, and copper together.  "+
      "To the north is the main foyer of the castle and the dining hall is to the south.  "+
      "The hall leads on to the east and west.\n";
  dest_dir=({
      HAM+"room/hall1", "north",
      HAM+"room/hall8", "south",
      HAM+"room/hall4", "east",
      HAM+"room/hall5", "west",
  });
  items=({
      "walls", "Lined with red velvet and trimmed with golden rope tassels",
      "velvet", "Dark red velvet",
      "tassels", "Golden rope tassels",
      "ceiling", "A tapestry is covering it",
      "tapestry", "A tapestry woven about a great battle",
      "floor", "It is covered with a fine Maltese style rug",
      "rug", "Red, gold, and copper woven together in a pleasing design",
  });
  clone_list=({
      1, 2, "guard", HAM+"npc/dguard", 0,
  });
  ::reset();
  replace_program("room/room");
}
