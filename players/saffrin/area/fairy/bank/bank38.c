inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Water Bank";
  long_desc = 
        "You are on the lush, green banks of Alfheim Stream.  Small gray pebbles are "+
        "scattered around you.  You can see the Knockaine Woods filled with willow trees to "+
        "the north of you.  There are several small moonworts growing along "+
        "the water's edge to the south of you.  The bank of the stream leads to "+
        "the east and west.\n";
  smell="It smells like the sweetness of flowers.\n";
  dest_dir=({
        FAIRY+"wood/wood12", "north",
        FAIRY+"water/stream12", "south",
        FAIRY+"bank/bank37", "east",
        FAIRY+"bank/bank39", "west",
  });
  items=({
        "banks", "The bank of the water",
        "you", "You cannot see yourself",
        "edge", "The edge of the water",
        "forest", "A thick forest of fir trees",
        "stream", "Alfheim Stream",
        "woods", "Knockaine Woods",
        "plant" , "A plant growing all around the water's edge",
        "moonworts", "A plant growing all around the water's edge",
        "water", "Rare silver water",
        "willow" , "Willow trees that have grown in thick",
        "trees" , "Willow trees that have grown in thick",
        "pebbles", "Small gray pebbles",
  });
  clone_list=({
        1, 2, "pwca", FAIRY+"npc/pwca", 0,
  });
  ::reset();
  replace_program("room/room");
}
