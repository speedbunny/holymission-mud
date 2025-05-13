inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg) {
  set_light(1);
  short_desc="Capricorn Research Room";
  long_desc=
      "This is the Capricorn research room of the mage tower.  This room is located "+
      "on the earth floor because Capricorn is one of the earth signs of the Zodiac.  There "+
      "is a large symbol of Capricorn on the west wall.  In the center of the room, "+
      "there is a pedestal with a glowing book on top of it.  Along the south wall, there are several "+
      "chairs in which a researcher may sit and read in.\n";
  dest_dir=({
      TOWER+"room/hall6", "east",
  });
  items=({
      "pedestal", "A pedestal with a book glowing on it",   
      "book", "Try: read capricorn",
      "shelf", "The shelves are filled with books",
      "books", "The books are very old and VERY dusty", 
      "chairs", "Comfortable chairs", 
  });
  clone_list=({
      1, 1, "fairy", TOWER+"npc/capri", 0,
  });
  ::reset();
}
init(){

  ::init();
    AA("read", "read");
  return 1;
}

read(str){
  if(str="capricorn") {
    cat(TOWER+"books/capri");
   return 1;
  }
 return 1;
}
