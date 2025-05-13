inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg) {
  set_light(1);
  short_desc="Aquarius Research Room";
  long_desc=
      "This is the Aquarius research room of the mage tower.  This room is located "+
      "on the air floor because Aquarius is one of the air signs of the Zodiac.  There "+
      "is a large symbol of Aquarius on the west wall.  In the center of the room, "+
      "there is a pedestal with a glowing book on top of it.  Along the south wall, there are several "+
      "chairs in which a researcher may sit and read in.\n";
  dest_dir=({
      TOWER+"room/hall5", "east",
  });
  items=({
      "pedestal", "A pedestal with a book glowing on it",   
      "book", "Try: read aquarius",
      "shelf", "The shelves are filled with books",
      "books", "The books are very old and VERY dusty", 
      "chairs", "Comfortable chairs", 
  });
  clone_list=({
      1, 1, "fairy", TOWER+"npc/aquari", 0,
  });
  ::reset();
}
init(){

  ::init();
    AA("read", "read");
  return 1;
}

read(str){
  if(str="aquarius") {
    cat(TOWER+"books/aquari");
   return 1;
  }
 return 1;
}
