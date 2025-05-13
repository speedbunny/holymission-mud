inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg) {
  set_light(1);
  short_desc="Virgo Research Room";
  long_desc=
      "This is the Virgo research room of the mage tower.  This room is located "+
      "on the earth floor because Virgo is one of the earth signs of the Zodiac.  There "+
      "is a large symbol of Virgo on the east wall.  In the center of the room, "+
      "there is a pedestal with a glowing book on top of it.  Along the north wall, there are several "+
      "chairs in which a researcher may sit and read in.\n";
  dest_dir=({
      TOWER+"room/hall6", "west",
  });
  items=({
      "pedestal", "A pedestal with a book glowing on it",   
      "book", "Try: read virgo",
      "shelf", "The shelves are filled with books",
      "books", "The books are very old and VERY dusty", 
      "chairs", "Comfortable chairs", 
  });
  clone_list=({
      1, 1, "fairy", TOWER+"npc/virgo", 0,
  });
  ::reset();
}
init(){

  ::init();
    AA("read", "read");
  return 1;
}

read(str){
  if(str="virgo") {
    cat(TOWER+"books/virgo");
   return 1;
  }
 return 1;
}
