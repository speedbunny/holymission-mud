inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg){
	set_light(0);
	short_desc= "Moldy moat";
	long_desc= "You can feel something swimming around your feet and legs, nibbling\n"+
	"at you. The moat water bubbles around your knees. Mold grows on the\n"+
	"water and fortress walls. Long black and brown reeds grow on the\n"+
	"water side. Something has popped out of the reeds as you walk by.\n"+
	"You can hear little whispers and giggles all around you.\n";
	items =
	({
	  "water","It is black and sticky",
	  "mold","Green and brown mold grows on the sides of the walls and water",
	  "walls","They have mold and fungus growing on them",
	  "reeds","Things seem to be moving around in them",
	});
clone_list = ({
1, 1, "maggot", "players/tuppence/fortress/monster/maggot", 0,
2, 1, "snake", "players/tuppence/fortress/monster/msnake", 0,
});
	dest_dir=
	({
	FROOM+"moat13","east",
	FROOM+"moat15","west",
	});
    }
::reset(arg);
replace_program("/room/room");
}
