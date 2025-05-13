inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Denmark's Castle Garden";
  long_desc = 
      "You are in a large garden of the castle of Denmark.  There are several shaped "+
      "bushes all along a white pebble path.  Roses and other flowers are all about in"+
      " intricate patterns of colorful delight.  The sun is shining brightly above, giving "+
      "a soft glow to all below.  Small trees give off just the right amount of shade to "+
      "protect everything from too much sun."+
      "  The small pebbles that make up the path lead to the north and east.\n";
  dest_dir=({
      HAM+"room/garden1", "north",
      HAM+"room/garden3", "east",
  });
  items=({
      "pebbles", "Small white pebbles making up a path",
      "bushes", "Various shapes and sizes",
      "flowers", "Roses and lilies",
      "trees", "Small trees giving off shade",
      "path", "A path made up small white pebbles",
      "gate", "A large iron gate to the graveyard",
      "sun", "Are you crazy, looking at the sun can make you blind",
  });
  clone_list=({      
      1, 2, "cardinal", HAM+"npc/card1", 0,
      1, 2, "cardinal", HAM+"npc/card2", 0,
  });
  ::reset();
  replace_program("room/room");
}
