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
      "protect everything from too much sun.  There is a large marble statue to the "+
      "north.  The small pebbles that make up the path lead to the south and west.\n";
  dest_dir=({
      HAM+"room/garden3", "south",
      HAM+"room/garden1", "west",
  });
/*
  hidden_dir=({
      HAM+"room/shake3", "enter",
  });
*/
  items=({
      "pebbles", "Small white pebbles making up a path",
      "statue", "A large marble statue.  There is a hole at the bottom of it",
      "hole", "Perhaps you could try to enter it",
      "bushes", "Various shapes and sizes",
      "flowers", "Roses and hyacinths",
      "trees", "Small trees giving off shade",
      "path", "A path made up small white pebbles",
      "gate", "A large iron gate to the graveyard",
      "sun", "Are you crazy, looking at the sun can make you blind",
  });
  clone_list=({        
      1, 3, "cardinal", HAM+"npc/card2", 0,
      1, 2, "cardinal", HAM+"npc/card1", 0,
  });
  ::reset();
  replace_program("room/room");
}
