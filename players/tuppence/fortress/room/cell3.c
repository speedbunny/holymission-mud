inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg){
	set_light(1);
	short_desc= "A lighted cell";
	long_desc= "You have entered a cell. Skeletons hangs from the walls in shackles.\n"+
	"You can smell the rotten bodys that are laying around. Death flaots\n"+
	"around the room. Rats nibble at the prisoners and the dead bodies\n"+
	"around the room.\n";
	items =
	({
	  "rats","The rats run away as they notice you looking at them",
	  "skeletons","the skeletons are still in the shackles they died in",
	  "bodies","Rotting bodies lay around from dead recent prisoners",
	});
clone_list = ({
1, 3, "prisoner", "/players/tuppence/fortress/monster/prisoner", 0,
});
	dest_dir= 
	({
	  FROOM+ "dun5","west",
	});
    }
::reset(arg);
replace_program("/room/room");
}
