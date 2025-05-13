inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg) {
  set_light(1);
  short_desc="Leo Research Room";
  long_desc=
      "This is the Leo research room of the mage tower.  This room is located "+
      "on the fire floor because Leo is one of the fire signs of the Zodiac.  There "+
      "is a large symbol of Leo on the east wall.  In the center of the room, "+
      "there is a pedestal with a glowing book on top of it.  Along the north wall, there are several "+
      "chairs in which a researcher may sit and read in.\n";
  dest_dir=({
      TOWER+"room/hall4", "west",
  });
  items=({
      "pedestal", "A pedestal with a book glowing on it",   
      "book", "Try: read leo",
      "shelf", "The shelves are filled with books",
      "books", "The books are very old and VERY dusty", 
      "chairs", "Comfortable chairs", 
  });
  clone_list=({
      1, 1, "fairy", TOWER+"npc/leo", 0,
  });
  ::reset();
}
init(){

  ::init();
    AA("read", "read");
  return 1;
}

read(str){
  if(str="leo") {
    cat(TOWER+"books/leo");
   return 1;
  }
 return 1;
}
