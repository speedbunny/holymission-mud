inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg){
	set_light(1);
	short_desc= "Slave room";
	long_desc= "This is where the slaves are put to work to make weapons, armours\n"+
	"and other stuff. Slaves of all races are being forced to work\n"+
	"here for the fortress. Guards and their hounds stand here to make\n"+
	"sure the slaves do their work. You can hear the guards crack their\n"+
	"whips on the slaves to make them work harder. There are several\n"+
	"forges for the slaves to make weapons.\n";
	items =
	({
	  "forges","Hot fires for the slaves to heat the weapons",
	});
clone_list = ({
1, 1, "guard", "players/tuppence/fortress/monster/saguard", 0,
-1, 1, "whip", "players/tuppence/fortress/weapon/whip", 0,
2, 2, "hound", "players/tuppence/fortress/monster/hound", 0,
-2, 1, "collar", "players/tuppence/fortress/armour/collar", 0,
3, 3, "slave", "players/tuppence/fortress/monster/slave", 0,
-3, 1, "shackles", "players/tuppence/fortress/armour/shackles", 0,
});
	dest_dir =
	({
	  FROOM+"dun6","west",
	});
    }
::reset(arg);
replace_program("/room/room");
}
