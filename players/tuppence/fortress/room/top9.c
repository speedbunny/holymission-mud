inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg) {
	set_light(1);
	short_desc= "Guarded room";
	long_desc= "This is a plain room, not much to see here except two guards\n"+
	"by an opened door. You can hear the crackling of great magic being\n"+
	"done inside the next room.\n";
clone_list = ({
1, 4, "guard", "players/tuppence/fortress/monster/mguard", 0,
-1, 1, "rod", "players/tuppence/fortress/weapon/rod", 0,
-1, 1, "cloak", "players/tuppence/fortress/armour/mcloak", 0,
});
	dest_dir=
	({
	  FROOM+"top7","north",
	  FROOM+"top10","east",
	});
    }
::reset(arg);
replace_program("/room/room");
}
