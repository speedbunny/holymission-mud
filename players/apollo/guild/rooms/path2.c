
inherit "room/room";

#include "/players/apollo/guild/barb.h"

void reset(int arg) {
   set_light(1);
  
   short_desc = "A well trodden path";

   long_desc =
	"The path leads to the east and west through a vast open plain."+
	" The rugged landscape extends far to the north and south from "+
	"here.\n";

   dest_dir = ({
	GROOMS+"path1","east",
	GROOMS+"path3","west",
	GROOMS+"open1","north",
	GROOMS+"open2","south",
     });

   items = ({
	"path", "It looks well used",
	"plain", "A wild untamed land",
     });

   replace_program("/room/room");
   ::reset(arg);

}
