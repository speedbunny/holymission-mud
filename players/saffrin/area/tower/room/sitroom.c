inherit "room/room";

#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Mage Tower Sitting Room";
  long_desc =
      "You are in the most relaxing room of the Mage Tower, the sitting room.  "+
      "Along the west wall is a large fireplace made from dark red bricks.  "+
      "A warm, crackling fire lights the room with a soft glow.  "+
      "There is a plush couch along the south wall with a blanket folded on the back.  "+
      "A small table is in front of the couch with scattered scrolls on top.\n";
  property=({ "has_fire" });
  dest_dir=({
      TOWER+"room/hall3", "east",
  });
  items=({
      "fireplace", "A large fireplace with a crackling fire",
      "bricks", "Dark red bricks making up a fireplace",
      "fire", "A warm, crackling fire giving off a glow",
      "glow", "A soft glow from the fire",
      "couch", "A plush couch",
      "cloth", "Dark green cloth",
      "blanket", "A cloth blanket",
      "back", "Back of the couch",
      "scrolls", "Scrolls that are impossible to read",
  });
  ::reset();
  replace_program("room/room");
}
