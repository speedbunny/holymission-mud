inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg) {
  set_light(1);
  short_desc="Cancer Research Room";
  long_desc=
      "This is the Cancer research room of the mage tower.  This room is located "+
      "on the water floor because Cancer is one of the water signs of the Zodiac.  There "+
      "is a large symbol of Cancer on the north wall.  In the center of the room, "+
      "there is a pedestal with a glowing book on top of it.  Along the east wall, there are several "+
      "chairs in which a researcher may sit and read in.\n";
  dest_dir=({
      TOWER+"room/hall7", "south",
  });
  items=({
      "pedestal", "A pedestal with a book glowing on it",
      "symbol", "The symbol for Cancer",   
      "book", "Try: read cancer",
      "shelf", "The shelves are filled with books",
      "books", "The books are very old and VERY dusty", 
      "chairs", "Comfortable chairs", 
  });
  clone_list=({
      1, 1, "fairy", TOWER+"npc/cancer", 0,
  });
  ::reset();
}
init(){

  ::init();
    AA("read", "read");
  return 1;
}

read(str){
  if(str="cancer") {
    cat(TOWER+"books/cancer");
   return 1;
  }
 return 1;
}
