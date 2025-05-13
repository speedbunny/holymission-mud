inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Water Bank";
  long_desc = 
        "You are on the lush, green banks of Elphame Lake.  There are several "+
        "small mandrakes growing along the water's edge to the east of you.  "+
      	"Small white pebbles are scattered around you.  You can see the "+
      	"Knockaine Woods filled with willow trees to the west of you.   The bank "+
        "of the lake leads to the north and south.\n";
  smell="It smells like the sweetness of flowers.\n";
  dest_dir=({
        FAIRY+"bank/bank33", "north",
        FAIRY+"bank/bank35", "south",
       	FAIRY+"water/lake32", "east",
        FAIRY+"wood/wood36", "west",
  });
  items=({
        "banks", "The bank of the water",
        "woods", "Knockaine Woods",
        "you", "You cannot see yourself",
        "edge", "The edge of the water",
        "forest", "A thick forest of fir trees",
        "lake", "Elphame Lake",
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
