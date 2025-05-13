inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg) {
  set_light(1);
  short_desc="Libra Research Room";
  long_desc=
      "This is the Libra research room of the mage tower.  This room is located "+
      "on the air floor because Libra is one of the air signs of the Zodiac.  There "+
      "is a large symbol of Libra on the east wall.  In the center of the room, "+
      "there is a pedestal with a glowing book on top of it.  Along the north wall, there are several "+
      "chairs in which a researcher may sit and read in.\n";
  dest_dir=({
      TOWER+"room/hall5", "west",
  });
  items=({
      "pedestal", "A pedestal with a book glowing on it",   
      "book", "Try: read libra",
      "shelf", "The shelves are filled with books",
      "books", "The books are very old and VERY dusty", 
      "chairs", "Comfortable chairs", 
  });
  clone_list=({
      1, 1, "fairy", TOWER+"npc/libra", 0,
  });
  ::reset();
}
init(){

  ::init();
    AA("read", "read");
  return 1;
}

read(str){
  if(str="libra") {
    cat(TOWER+"books/libra");
   return 1;
  }
 return 1;
}
