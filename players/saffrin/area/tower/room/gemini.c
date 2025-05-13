inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg) {
  set_light(1);
  short_desc="Gemini Research Room";
  long_desc=
      "This is the Gemini research room of the mage tower.  This room is located "+
      "on the air floor because Gemini is one of the air signs of the Zodiac.  There "+
      "is a large symbol of Gemini on the north wall.  In the center of the room, "+
      "there is a pedestal with a glowing book on top of it.  Along the east wall, there are several "+
      "chairs in which a researcher may sit and read in.\n";
  dest_dir=({
      TOWER+"room/hall5", "south",
  });
  items=({
      "pedestal", "A pedestal with a book glowing on it",
      "symbol", "The symbol for Gemini",   
      "book", "Try: read gemini",
      "shelf", "The shelves are filled with books",
      "books", "The books are very old and VERY dusty", 
      "chairs", "Comfortable chairs", 
  });
  clone_list=({
      1, 2, "fairy", TOWER+"npc/gemini", 0,
  });
  ::reset();
}
init(){

  ::init();
    AA("read", "read");
  return 1;
}

read(str){
  if(str="gemini") {
    cat(TOWER+"books/gemini");
   return 1;
  }
 return 1;
}
