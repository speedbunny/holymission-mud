inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Cherlindrea's Workroom";
  long_desc =
      "This is Cherlindrea's workroom in the Mage Tower.  Along the north wall is a "+
      "large desk made from shimmering carved jade.  A small moon goddess statue is "+
      "sitting on the desk.  Next to the west door is a large bookcase filled with tomes.  "+
      "A window is in the east wall with a trunk next to it.  The curtains "+
      "are made from soft green cloth.  Dark green candles and vanilla incense are "+
      "burning around the room.  There is a doorway to the southwest.\n";
  property=({ "has_fire" });
  dest_dir=({
      TOWER+"room/hall8", "west",
      TOWER+"room/cherbed", "southwest",
  });
  items=({
      "incense", "Long thin incense sticks buring in the room",
      "trunk", "Do not peak at Cherlindrea's secret spells",
      "bookcase", "Filled with tomes",
      "tomes", "Tomes on spells, castings and vanilla",
      "desk", "A large desk made from carved jade",
      "jade", "Shimmering carved jade",
      "statue", "A statue of Artemis, the goddess of the moon",
      "artemis", "The goddess of the moon",
      "curtains", "Soft green curtains",
      "window", "As you look out the window, you can see the lush land",
      "land", "Dark green trees is all you can see for miles", 
      "trees", "Many kinds of dark green trees",
      "candles", "Dark green candles lighting the room",
  });
  smell="You smell vanilla all around you.";
  clone_list =({
      1, 1, "cherlindrea", TOWER+"npc/cherlind", 0,
  });
  ::reset();
  replace_program("room/room");
}
