inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg) {
  set_light(1);
  short_desc="Taurus Research Room";
  long_desc=
      "This is the Taurus research room of the mage tower.  This room is located "+
      "on the earth floor because Taurus is one of the earth signs of the Zodiac.  There "+
      "is a large symbol of Taurus on the north wall.  In the center of the room, "+
      "there is a pedestal with a glowing book on top of it.  Along the east wall, there are several "+
      "chairs in which a researcher may sit and read in.\n";
  dest_dir=({
      TOWER+"room/hall6", "south",
  });
  items=({
      "pedestal", "A pedestal with a book glowing on it",
      "symbol", "The symbol for Taurus",   
      "book", "Try: read taurus",
      "shelf", "The shelves are filled with books",
      "books", "The books are very old and VERY dusty", 
      "chairs", "Comfortable chairs", 
  });
  clone_list=({
      1, 1, "fairy", TOWER+"npc/taurus", 0,
  });
  ::reset();
}
init(){

  ::init();
    AA("read", "read");
  return 1;
}

read(str){
  if(str="taurus") {
    cat(TOWER+"books/taurus");
   return 1;
  }
 return 1;
}
