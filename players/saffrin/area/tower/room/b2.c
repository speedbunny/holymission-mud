inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Mage Tower Battlements";
  long_desc =
        "You are on the crystal battlements at the top of the Mage Tower.  "+
        "The view of the land expands to the west of the tower.  A moonstone "+
         "railing is on the west edge, protecting all from falling.  The battlements "+
        "continue to the northeast and southeast.  A stairwell back into the "+
        "tower is to the east.\n";
  dest_dir=({
      TOWER+"room/top", "east",
      TOWER+"room/b1", "northeast",
      TOWER+"room/b3", "southeast",
  });
  items=({
      "battlements", "Crystal battlements",
      "crystal", "Crystal battlements",
      "railing", "Railing made from moonstone",
      "moonstone", "Moonstone making up a railing",
      "view", "A beautiful view of the land",
      "land", "A beautiful view of the land",
      "edge", "The edge of the battlements",
      "tower", "The mage tower",
      "stairwell", "The stairwell into the mage tower",
  });
  smell="You smell flowers all around you.";
  ::reset();
  replace_program("room/room");
}
