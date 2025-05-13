
inherit "room/room";

#include "/players/apollo/guild/barb.h"

void reset(int arg) {
   set_light(1);

   short_desc = "On the Barbarian Plains";

   long_desc = 
	"You stand on a vast rocky plain. The openess of the land "+
	"instills you with a feeling of freedom. The plains meet "+
	"mountain range here, which rises above you to the west. Even "+
	"the most talented barbarian could not hope to climb this slope.\n";

   dest_dir = ({
	GROOMS+"open16","east",
	GROOMS+"open21","south",
     });

   items = ({
	"plain", "A rugged and untamed plain",
	"plains", "A rugged and untamed plain",
	"mountains", "They rise above the plain to the west",
	"range", "A mountain range rises above the plain to the west",
     });

   replace_program("/room/room");
   ::reset(arg);

}
