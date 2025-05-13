inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Mage-Master Yorel's Workroom";
  long_desc =
      "You are in Mage-Master Yorel's workroom on the Mage Tower.  "+
       "There is a large oak work desk along the south wall.  In "+
       "front of the desk, there is a small chair with a brass frame.  "+
       "A spiral staircase is in the center of the room, leading up "+
       "to Mage-Master Yorel's bedroom.  A globe of fireflies keeps the "+
       "room well lit.  The hallway is to the north.\n";
  dest_dir=({
      TOWER+"room/hall6", "north",
      TOWER+"room/yorbed", "up",
  });
  items=({
      "walls", "Dark stone walls that are bare and plain",
      "desk", "A large desk made from oak",
      "oak", "Oak that makes up a desk",
      "chair", "A chair made with a brass frame",
      "frame", "The frame of a chair made from brass",
      "brass", "Brass making up the frame of the chair",
      "staircase", "A spiral staricase",
      "fireflies", "A globe of fireflies",
      "globe", "A globe of fireflies",
      "bedroom", "Mage-Master Yorel's bedroom",
      "room", "Mage-Master Yorel's Workroom",
      "hallway", "The hallway of the mage tower",
      "tower", "The mage tower",
      "bedroom", "Mage-Master Yorel's bedroom",
  });
  ::reset();
  replace_program("room/room");
}
