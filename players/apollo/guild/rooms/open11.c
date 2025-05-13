
inherit "room/room";

#include "/players/apollo/guild/barb.h"

void reset(int arg) {
   set_light(1);

   short_desc = "On the Barbarian Plains";

   long_desc = 
	"You stand on a vast rocky plain. Trees lace the north and the bad "+
	"smell of orcs drift through the air. The openess of the land "+
	"instills you with a feeling of freedom. Far to the west, a "+
	"range of mountains towers over this land.\n";

   dest_dir = ({
	GROOMS+"open6","east",
	GROOMS+"open9","south",
	GROOMS+"open15","west",
     });

   items = ({
	"plain", "A rugged and untamed plain",
	"plains", "A rugged and untamed plain",
	"mountains", "They rise above the plain to the west",
	"range", "A mountain range rises above the plain to the west",
	"trees", "The trees line the north",
   });

   clone_list = ({ 1, 1, "bull", GMONSTERS+"bull", 0, });

   replace_program("/room/room");
   ::reset(arg);

}
