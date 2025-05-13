
inherit "room/room";

#include "/players/apollo/guild/barb.h"

void reset(int arg) {
   set_light(1);

   short_desc = "On the Barbarian Plains";

   long_desc = 
	"You stand on a vast rocky plain. The openess of the land "+
	"instills you with a feeling of freedom. Far to the west, a "+
	"range of mountains towers over this land. To the north, a large "+
	"range of trees cover the land.\n";

   dest_dir = ({
	GROOMS+"open13","south",
	GROOMS+"open16","west",
	GROOMS+"open11","east",
     });

   items = ({
	"plain", "A rugged and untamed plain",
	"plains", "A rugged and untamed plain",
	"mountains", "They rise above the plain to the west",
	"range", "A mountain range rises above the plain to the west",
     });

   clone_list = ({ 1, 2, "prairie_dog", GMONSTERS+"prairie_dog", 0, });
  
   replace_program("/room/room");
   ::reset(arg);

}
