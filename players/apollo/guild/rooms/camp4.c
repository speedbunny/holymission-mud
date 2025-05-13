
inherit "room/room";

#include "/players/apollo/guild/barb.h"

void reset(int arg) {
   set_light(1);
   
   short_desc = "In the barbarian camp";

   long_desc = 
	"You stand in the midst of the Barbarian camp. These people "+
	"have made their camp at the foot of a mountain range. Barbarians "+
	"eye you closely as you make your way through the camp. "+
	"There are large tents heading to the east and the west.\n";

   dest_dir = ({
	GROOMS+"camp2","north",
	GROOMS+"camp5","south",
	GROOMS+"weap_shop","west",
	GROOMS+"armour_shop","east",
     });

   items = ({
	"path", "It looks well used",
	"plain", "A wild untamed land",
     });

   replace_program("/room/room");
   ::reset(arg);

}
