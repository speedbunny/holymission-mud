inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Cherlindrea's Bedroom";
  long_desc =
      "This is Cherlindrea's bedroom in the Mage Tower.  Along the south wall is a "+
      "large bed made from soft rose petals.  A cute little teddy bear is "+
      "sitting on the bed.  Next to the north door is a large bookcase filled with books.  "+
      "A window is in the west wall with a closet next to it.  The curtains "+
      "are made from rose print cloth.  Soft green candles and rose incense are "+
      "burning around the room.  There is an open doorway to the northeast.\n";
  property=({ "has_fire" });
  dest_dir=({
      TOWER+"room/hall8", "north",
      TOWER+"room/cherwork", "northeast",
  });
  items=({
      "door", "A door to the mage tower staircase",
      "doorway", "A doorway to Cherlindrea's workroom",
      "incense", "Long thin incense sticks buring in the room",
      "closet", "Do not peak at Cherlindrea's unmentionables",
      "bookcase", "Filled with books",
      "books", "Books on spells, castings and roses",
      "bed", "A soft bed made from rose petals",
      "petals", "Soft petals",
      "roses", "Beautiful wine colored roses",
      "bear", "Cherlindrea's teddy bear named Cedric",
      "cedric", "A cute, little teddy bear",
      "curtains", "Rose print curtains",
      "window", "As you look out the window, you can see the lush land",
      "land", "Dark green trees is all you can see for miles", 
      "trees", "Many kinds of dark green trees",
      "candles", "Soft green candles lighting the room",
  });
  smell="You smell roses all around you.";
  ::reset();
  replace_program("room/room");
}
