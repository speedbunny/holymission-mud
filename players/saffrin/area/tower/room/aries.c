inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg) {
  set_light(1);
  short_desc="Aries Research Room";
  long_desc=
      "This is the Aries research room of the mage tower.  This room is located "+
      "on the fire floor because Aries is one of the fire signs of the Zodiac.  There "+
      "is a large symbol of Aries on the north wall.  In the center of the room, "+
      "there is a pedestal with a glowing book on top of it.  Along the east wall, there are several "+
      "chairs in which a researcher may sit and read in.\n";
  dest_dir=({
      TOWER+"room/hall4", "south",
  });
  items=({
      "pedestal", "A pedestal with a book glowing on it",
      "symbol", "The symbol for Aries",   
      "book", "Try: read aries",
      "shelf", "The shelves are filled with books",
      "books", "The books are very old and VERY dusty", 
      "chairs", "Comfortable chairs", 
  });
  clone_list=({
      1, 1, "fairy", TOWER+"npc/aries", 0,
  });
  ::reset();
}
init(){

  ::init();
    AA("read", "read");
  return 1;
}

read(str){
  if(str="aries") {
    cat(TOWER+"books/aries");
   return 1;
  }
 return 1;
}
