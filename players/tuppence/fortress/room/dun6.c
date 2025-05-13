inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg){
	set_light(0);
	short_desc= "Dark dungeon";
	long_desc= "The stands seem to have been knocked over, the oils make the floor\n"+
	"slippery. A giant shadow creeper slithers out from the shadows. He\n"+
	"must have turned over the stands to make it dark. Banging and voices\n"+
	"come from the east and there is another cell to the west.\n";
	items =
	({
	  "stands","They have been knocked over to make the place dark",
	  "shadows","They seem to have something moving in it",
	});
clone_list = ({
1, 1, "creeper", "players/tuppence/fortress/monster/creep", 0,
});
	dest_dir =
	({
	  FROOM+"cell4","west",
	  FROOM+"dun7","north",
	  FROOM+"savroom","east",
	  FROOM+"dun5","south",
	});
    }
::reset(arg);
replace_program("/room/room");
}
