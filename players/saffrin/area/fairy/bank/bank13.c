inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Water Bank";
  long_desc = 
        "You are on the lush, green banks of Alfheim Stream.  There are several "+
        "small mandrakes growing along the water's edge to the north of you.  "+
      	"Small white pebbles are scattered around you.  You can see a thick "+
      	"forest filled with fir trees in the south.  To the northeast is the "+
        "edge of Elphame Lake.\n";
  smell="It smells like the sweetness of flowers.\n";
  dest_dir=({
        FAIRY+"water/stream13", "north",
        FAIRY+"bank/bank14", "east",
       	FAIRY+"bank/bank12", "west",
  });
  items=({
        "banks", "The bank of the water",
        "you", "You cannot see yourself",
        "edge", "The edge of the water",
        "forest", "A thick forest of fir trees",
        "stream", "Alfheim Stream",
        "plant" , "A plant growing all around the water's edge",
        "mandrakes", "A plant growing all around the water's edge",
        "lake", "Silver watered Elphame Lake",
        "water", "Rare silver water",
        "fir" , "Fir trees that have grown in thick",
        "trees" , "Fir trees that have grown in thick",
        "pebbles", "Small white pebbles",
  });
  ::reset();
  replace_program("room/room");
}
