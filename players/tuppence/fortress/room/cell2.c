inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg){
	set_light(1);
	short_desc= "A dirty cell";
	long_desc= "This cell is more dirty then the others, if you can believe that.\n"+
	"The prisoners look as if they have been here for a long time. They\n"+
	"can't even stand anymore they are so weak from torture. Moldy hay is\n"+
	"thrown about the ground to soak up the blood the prisoners leave\n"+
	"behind. The walls are made out of a cold stone.\n";
	items =
	({
	  "hay","It is moldy from rotten human blood",
	  "wells","Cold to the touch, they give you goose bumps",
	});
clone_list = ({
1, 3, "prisoner", "players/tuppence/fortress/monster/prisoner", 0,
});
	dest_dir=
	({
	  FROOM+ "dun4","east",
	});
    }
::reset(arg);
replace_program("/room/room");
}
