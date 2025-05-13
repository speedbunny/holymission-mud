
inherit "room/room";

#include "/players/apollo/guild/barb.h"

void reset(int arg) {
   set_light(1);

   short_desc = "On the Barbarian Plains";

   long_desc = 
	"You stand on a vast rocky plain. The openess of the land "+
	"instills you with a feeling of freedom. Far to the west, a "+
	"range of mountains towers over this land. To the north, a large "+
	"forest surrounds the land.\n";

   dest_dir = ({
	GROOMS+"open11","north",
	GROOMS+"open7","south",
	GROOMS+"open3","east",
	GROOMS+"open13","west",
     });

   items = ({
	"plain", "A rugged and untamed plain",
	"plains", "A rugged and untamed plain",
	"mountains", "They rise above the plain to the west",
	"range", "A mountain range rises above the plain to the west",
     });

   clone_list = ({ 1, 2, "donkey", GMONSTERS+"donkey", 0, });

   replace_program("/room/room");
   ::reset(arg);

}
