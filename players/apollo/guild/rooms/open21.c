
inherit "room/room";

#include "/players/apollo/guild/barb.h"

void reset(int arg) {
   set_light(1);

   short_desc = "On the Barbarian Plains";

   long_desc = 
	"You stand on a vast rocky plain. The openess of the land "+
	"instills you with a feeling of freedom. The plains meet "+
	"mountain range here, which rises above you to the west. It "+
	"appears possible to climb up from here on a small slope running "+
	"up to the west.  Many small footprints lead up the slope.\n";

   dest_dir = ({
	GROOMS+"open17","north",
	GROOMS+"open19","east",
     });

   items = ({
	"plain", "A rugged and untamed plain",
	"plains", "A rugged and untamed plain",
	"slope", "It leads up to the west",
	"footprints", "Very small bidedal footprints with claws",
	"mountains", "They rise above the plain to the west",
	"range", "A mountain range rises above the plain to the west",
     });

   replace_program("/room/room");
   ::reset(arg);

}
