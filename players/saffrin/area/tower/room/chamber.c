inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg) {
  set_light(1);
  short_desc="Mage Research Chamber";
  long_desc=
      "This is the Mage Research Chamber of the mage tower.  There are several "+
      "books lining the room's walls.  In the center of the room, there is a pedestal "+
      "with a glowing book on top of it.  Along the north wall, there are several "+
      "chairs in which a researcher may sit and read in.  Most mages find this "+
      "room informative.\n";
  property=({ "no_fight", "no_teleport" });
  dest_dir=({
      TOWER+"room/hall3", "south",
  });
  items=({
      "pedestal", "A pedestal with a book glowing on it",   
      "book", "Try: read mages",
      "shelf", "The shelves are filled with books",
      "books", "The books are very old and VERY dusty", 
      "chairs", "Comfortable chairs", 
  });
  ::reset();
}
init(){

  ::init();
    AA("read", "read");
  return 1;
}

read(str){
  if(str="mages") {
    cat(TOWER+"books/mage/mages");
   return 1;
  }
 return 1;
}
