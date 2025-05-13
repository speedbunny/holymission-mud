
inherit "room/room";

#include "/players/apollo/guild/barb.h"

void reset(int arg) {
   set_light(1);
   
   short_desc = "In the barbarian camp";

   long_desc = 
	"You stand in the midst of the Barbarian camp. These people "+
	"have made their camp at the foot of a mountain range. Barbarians "+
	"eye you closely as you make your way through the camp. "+
	"There are large tents to the east and the west.\n";
 
   dest_dir = ({
	GROOMS+"open19","north",
	GROOMS+"shaman_room","east",
	GROOMS+"magic_dest","west",
	GROOMS+"camp2","south",
     });
  
   items = ({
	"path", "It looks well used",
	"plain", "A wild untamed land",
     });

   replace_program("/room/room");
   ::reset(arg);

}
