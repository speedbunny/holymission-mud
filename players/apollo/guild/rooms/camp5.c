
inherit "room/room";

#include "/players/apollo/guild/barb.h"

void reset(int arg) {
   set_light(1);
 
   short_desc = "In the barbarian camp";
 
   long_desc = 
	"You stand in the midst of the Barbarian camp. These people "+
	"have made their camp at the foot of a mountain range. Barbarians "+
	"stop what they are doing and you closely as you make your way "+ 
	"through the camp. There is a small tent to the west.\n";

   dest_dir = ({
	GROOMS+"tent2","west",
	GROOMS+"camp4","north",
	GROOMS+"open14","east",
	GROOMS+"open18","south",
     });
 
   items = ({
	"path", "It looks well used",
	"plain", "A wild untamed land",
     });

   replace_program("/room/room");
   ::reset(arg);

}
