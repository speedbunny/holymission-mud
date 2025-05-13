
inherit "room/room";

#include "/players/apollo/guild/barb.h"

void reset (int arg) {
   set_light(1);

   short_desc = "On a vast open plain";

   long_desc = 
	"You are standing on a vast open plain. To the north lies an "+ 
	"encampment of barbarians, who have made their home at the foot "+ 
	"of the mountain range.\n";

   dest_dir = ({
	GROOMS+"camp5","north",
	GROOMS+"crag","east",
	GROOMS+"open20","west",
     });

   items = ({
	"path", "It looks well used",
	"plain", "A wild untamed land",
     });

   clone_list = ({ 1, 4, "bear", GMONSTERS+"bear", 0, });

   replace_program("/room/room");
   ::reset(arg);

}
