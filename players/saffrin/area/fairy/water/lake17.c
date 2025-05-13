inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg){
  set_light(1);
  short_desc = "Elphame Lake";
  long_desc = 
        "You are standing in the sacred lake of the fairies, known as Elphame "+
	"Lake.  The water of this lake is a rare silver color, that is said to have "+
        "been created from moondust.  Glimmering sparkles rain down from above, "+
        "glistening you skin.    Strange lights fly by your head, whispering "+
        "chants in your ears.  Several waterlilies float on the surface "+
 	"of the water, adding a soft white touch to the silvery glow\n";
  smell="It smells like the sweetness of flowers.\n";
  dest_dir=({
        FAIRY+"water/lake18", "north",
        FAIRY+"bank/bank17", "south",
        FAIRY+"bank/bank19", "east",
        FAIRY+"water/lake16", "west",
        FAIRY+"bank/bank18", "southeast",
  });
  items=({
	"lake", "The sacred Elphame Lake",
	"water", "Rare silver water",
	"moondust", "Glimmering moondust sparkles",
	"sparkles", "Glimmering moondust sparkles",
	"lillies", "Soft white water lilies",
	"flies", "Small fireflies whispering by you",
	"fireflies", "Small fireflies whispering by you",
	"lights", "Small fireflies whispering by you",
	"glow", "A silvery glow from the water",
        "banks", "The bank of the water",
        "you", "You cannot see yourself",
        "head", "You cannot see your head",
        "ears", "You cannot see your ears",
        "chants", "You cannot see chants",
        "fairies", "This is the lake of the fairies",
        "color", "Silver",
        "silver", "The color silver",
        "edge", "The edge of the water",
  });
  clone_list=({
        1, 3, "gwragedd", FAIRY+"npc/gwra", 0,
  });
  ::reset();
  replace_program("room/room");
}
