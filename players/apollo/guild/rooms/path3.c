
inherit "room/room";

#include "/players/apollo/guild/barb.h"

void reset(int arg) {
   set_light(1);

   short_desc = "A well trodden path";

   long_desc = 
	"The path leads to the east and west through a vast open plain."+
	" The rugged landscape extends far to the north and south from "+
	"here. The path leads into a small barbarian camp, just to the "+
	"west.\n";
 
   dest_dir = ({
	GROOMS+"open7","north",
	GROOMS+"open8","south",
	GROOMS+"path2","east",
	GROOMS+"camp1","west",
     });
 
   items = ({
	"path", "It looks well used",
	"plain", "A wild untamed land",
     });

   replace_program("/room/room");
   ::reset(arg);

}
