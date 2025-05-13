inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "The castle's receiving room";
  long_desc = 
      "You are in the receiving room for the castle of Denmark's guests.  There is a large "+
      "leather couch along the west wall with a small oak tea cart by its side.  A sterling silver "+
      "tea set is on the cart with a large tray to match.  The north wall is made up entirely "+
      "of shelves filled with books of all colors and sizes.  The walls are painted a soft "+
      "white with the edges done lightly in gold.\n";
  dest_dir=({
      HAM+"room/hall1", "west",
  });
  items=({
      "couch", "A large cream colored leather couch",
      "cart", "A small tea cart made from the finest oak",
      "set", "A sterling silver tea set",
      "tray", "A sterling silver tray",
      "books", "Of all colors and sizes",
      "shelves", "Filled with books",
      "walls", "Painted a soft white",
  });
  clone_list=({
      1, 1, "reynaldo", HAM+"npc/reynaldo", 0,
  });
  ::reset();
  replace_program("room/room");
}
