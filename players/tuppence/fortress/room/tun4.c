inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg){
	set_light(1);
	short_desc= "End of tunnel";
	long_desc= "You have come to the end of the tunnel, you about pass out from\n"+
	"the smell coming out of the next room. Scratching and high pitched\n"+
	"growling comes from the north, you wonder what could be up there.\n"+
	"The water height seems to get lower here.\n";
	items =
	({
	  "water","It has lowered its height",
	});
clone_list = ({
1, 1, "frog", "players/tuppence/fortress/monster/hfrog", 0,
-1, 1, "horn", "players/tuppence/fortress/weapon/fhorn", 0,
2, 1, "spider", "players/tuppence/fortress/monster/spider", 0,
-2, 1, "web", "players/tuppence/fortress/armour/web", 0,
});
	dest_dir= 
	({
	  FROOM+"tun3","south",
	  FROOM+"nest","north",
	});
    }
::reset(arg);
replace_program("/room/room");
}
