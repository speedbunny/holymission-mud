inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Alfheim Stream";
  long_desc = 
        "You are standing in Alfheim Stream, which is known for its rare silver water.  "+
        "The banks of the stream are lined with mugwort, moonwort, and "+
        "mandrakes.  A few large rocks are scattered throughout the water, "+
        "causing small rapids to form.  There are several water lilies growing up "+
        "from the shimmering surface.\n";
  smell="It smells like the sweetness of flowers.\n";
  dest_dir=({
        FAIRY+"bank/bank43", "north",
        FAIRY+"bank/bank7", "south",
        FAIRY+"water/stream8", "east",
        FAIRY+"water/stream6", "west",
  });
  items=({
	"stream", "The sacred Alfheim Stream",
        "surface", "Has flowers growing up from it",
        "banks", "There is mugwort, moonwort, and mandrake growing there",
        "mandrake", "Plants growing on the bank",
        "mugwort", "Plants growing on the bank",
        "moonwort", "Plants growing on the bank",
        "rapids", "Tiny silver rapids caused by rocks",
        "rocks", "White rocks causing rapids",
	"water", "Rare silver water",
	"moondust", "Glimmering moondust sparkles",
	"sparkles", "Glimmering moondust sparkles",
	"lillies", "Soft white water lilies",
	"flowers", "Soft white water lilies",
	"flies", "Small fireflies whispering by you",
	"fireflies", "Small fireflies whispering by you",
	"lights", "Small fireflies whispering by you",
	"glow", "A silvery glow from the water",
        "banks", "The bank of the water",
        "edge", "The edge of the water",
  });
  clone_list=({
        1, 1, "pisky", FAIRY+"npc/pisky", 0,
  });
  ::reset();
  replace_program("room/room");
}
