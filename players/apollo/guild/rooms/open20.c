
inherit "room/room";

#include "/players/apollo/guild/barb.h"

void reset(int arg) {
   set_light(1);

   short_desc = "On the Barbarian Plains";

   long_desc =
        "You stand on a vast rocky plain. The openness of the land "+
        "instills you with a feeling of freedom. The plains meet a "+
	"mountain range here, which rises above you to the west. Even "+
	"the most talented barbarian could not hope to climb this slope. "+
	"Occasionally large boulders and rocks fall down from the slope "+
	"above.\n";

   dest_dir=({
	GROOMS+"open18","east",
     });

   items = ({
	"plain", "A rugged and untamed plain",
	"plains", "A rugged and untamed plain",
	"mountains", "They rise above the plain to the west",
	"range", "A mountain range rises above the plain to the west",
     });

   clone_list = ({ 1, 7, "boulders", GOBJS+"boulder", 0,
                   2, 13, "rock", GOBJS+"rock", 0, });

   replace_program("/room/room");
   ::reset(arg);

}
