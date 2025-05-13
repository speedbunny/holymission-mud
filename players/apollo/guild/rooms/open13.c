
inherit "room/room";

#include "/players/apollo/guild/barb.h"

void reset(int arg) {
   set_light(1);

   short_desc = "On the Barbarian Plains";

   long_desc = 
	"You stand on a vast rocky plain. The openess of the land "+
	"instills you with a feeling of freedom. Far to the west, a "+
	"range of mountains towers over this land. To the south, smoke "+
	"rises above the mountains and trees.\n";

   dest_dir = ({
	GROOMS+"open15","north",
	GROOMS+"open9","east",
	GROOMS+"open19","west",
     });

   items = ({
	"plain", "A rugged and untamed plain",
	"plains", "A rugged and untamed plain",
	"mountains", "They rise above the plain to the west",
	"range", "A mountain range rises above the plain to the west",
     });

   clone_list = ({ 1, 6, "prairie_dog", GMONSTERS+"prairie_dog", 0, });

   replace_program("/room/room");
   ::reset(arg); 

}
