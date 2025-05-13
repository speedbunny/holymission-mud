inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Water Bank";
  long_desc = 
        "You are on the lush, green banks of Alfheim Stream.  There are several "+
        " small mugworts growing along the water's edge to the north of you.  "+
        "Small brown pebbles are scattered around you.  You can see a thick "+
        "forest filled with fir trees to the south of you.  The bank of the "+
        "stream leads to the east and west.\n";
  smell="It smells like the sweetness of flowers.\n";
  dest_dir=({
        FAIRY+"water/stream9", "north",
        FAIRY+"bank/bank10", "east",
        FAIRY+"bank/bank8", "west",
  });
  items=({
        "banks", "The bank of the water",
        "you", "You cannot see yourself",
        "edge", "The edge of the water",
        "forest", "A thick forest of fir trees",
        "stream", "Alfheim Stream",
        "plant" , "A plant growing all around the water's edge",
        "mugworts", "A plant growing all around the water's edge",
        "water", "Rare silver water",
        "fir" , "Fir trees that have grown in thick",
        "trees" , "Fir trees that have grown in thick",
        "pebbles", "Small brown pebbles",
  });
  clone_list=({
        1, 2, "fay", FAIRY+"npc/fay", 0,
  });
  ::reset();
  replace_program("room/room");
}
