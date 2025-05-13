
inherit "room/room";

#include "/players/apollo/guild/barb.h"

void reset(int arg) {
   set_light(1);

   short_desc = "In the barbarian camp";

   long_desc = 
	"You stand in the midst of the Barbarian camp. These people "+
	"have made their camp at the foot of a mountain range. Barbarians "+
	"stop what they are doing to watch you closely as you make your way "+ 
	"through the camp.\n";
 
   dest_dir = ({
	GROOMS+"path3","east",
	GROOMS+"camp2","west",
     });

   items = ({
	"path", "It looks well used",
	"plain", "A wild untamed land",
     });

   clone_list = ({ 1, 3, "guard", GMONSTERS+"guard", 0, });

   replace_program("/room/room");
   ::reset(arg);

}
