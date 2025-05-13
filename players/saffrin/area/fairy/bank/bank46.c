inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Water Bank";
  long_desc = 
        "You are on the lush, green banks of Alfheim Stream.  There are several "+
        "small mandrakes growing along the water's edge to the south of you.  "+
      	"Small white pebbles are scattered around you.  You can see the "+
      	"Knockaine Woods filled with willow trees to the north of you.   The bank "+
        "of the stream leads to the east and west.\n";
  smell="It smells like the sweetness of flowers.\n";
  dest_dir=({
        FAIRY+"wood/wood4", "north",
        FAIRY+"water/stream4", "south",
       	FAIRY+"bank/bank45", "east",
        FAIRY+"bank/bank47", "west",
  });
  items=({
        "banks", "The bank of the water",
        "woods", "Knockaine Woods",
        "you", "You cannot see yourself",
        "edge", "The edge of the water",
        "forest", "A thick forest of fir trees",
        "stream", "Alfheim Stream",
        "plant" , "A plant growing all around the water's edge",
        "mandrakes", "A plant growing all around the water's edge",
        "water", "Rare silver water",
        "willow" , "Willow trees that have grown in thick",
        "trees" , "Willow trees that have grown in thick",
        "pebbles", "Small white pebbles",
  });
  ::reset();
  replace_program("room/room");
}
