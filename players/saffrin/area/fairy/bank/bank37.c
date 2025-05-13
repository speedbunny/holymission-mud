inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Water Bank";
  long_desc = 
        "You are on the lush, green banks of Elphame Lake and Alfheim Stream.  There are several "+
        "small mandrakes growing along the water's edge to the east, south, and southeast of you.  "+
      	"Small white pebbles are scattered around you.  You can see the "+
      	"Knockaine Woods filled with willow trees to the northwest of you.   The bank "+
        "of the lake leads to the north and to the west becomes the stream bank.\n";
  smell="It smells like the sweetness of flowers.\n";
  dest_dir=({
        FAIRY+"bank/bank36", "north",
        FAIRY+"water/stream13", "south",
       	FAIRY+"water/lake39", "east",
        FAIRY+"bank/bank38", "west",
        FAIRY+"wood/wood12", "northwest",
        FAIRY+"water/lake14", "southeast",
  });
  items=({
        "banks", "The bank of the water",
        "woods", "Knockaine Woods",
        "you", "You cannot see yourself",
        "edge", "The edge of the water",
        "forest", "A thick forest of fir trees",
        "lake", "Elphame Lake",
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
