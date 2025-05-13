
inherit "room/room";

#include "/players/apollo/guild/barb.h"

void reset(int arg) {
   set_light(1);

   short_desc = "On a vast open plain";

   long_desc = 
	"You are standing on a vast open plain. To the south lies an "+ 
	"encampment of barbarians, who have made their home at the foot "+ 
	"of the mountain range.\n";

   dest_dir = ({
	GROOMS+"camp3","south",
	GROOMS+"open16","north",
	GROOMS+"open13","east",
	GROOMS+"open21","west",
     });

   items = ({
	"path", "It looks well used",
	"plain", "A wild untamed land",
     });

   replace_program("/room/room");
   ::reset(arg);

}
