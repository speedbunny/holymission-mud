inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg){
	set_light(0);
	short_desc= "Dark dungeon";
	long_desc= "You have entered a dark damp dungeon. Small scratch marks\n"+
	           "are on the ground and walls, you wonder where they came from.\n"+
		   "As you look down you see slime all over the floor, you wonder\n"+
		   "what left that behind. The ceiling looks as if it will fall\n"+
		   "upon you at anytime. Moss hangs off the walls with blood\n"+
	           "splattered on it.\n";
	items =
	({
	  "ceiling","You had better leave before the ceiling falls",
	  "walls","They have some moss and fungus growing on them.",
	  "blood","It must have come from the prisoners that are kept down here",
	});
clone_list = ({
1, 1, "slime", "players/tuppence/fortress/monster/slime", 0,
});
	dest_dir=
	({
	  FROOM+"hall5","up",
	  FROOM+"dun2","west",
	});
    }
::reset(arg);
replace_program("/room/room");
}
