inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg){
	set_light(1);
	short_desc= "Guards bedroom";
	long_desc= "These are the sleeping guarters of the soldier. It is humid\n"+
	"and dirty here, maybe that is why the guards here are in such\n"+
	"a bad mood.\n";
clone_list = ({
1, 2, "guard", "players/tuppence/fortress/monster/slguard", 0,
});
	dest_dir = 
	({
	  FROOM+"hall3","west",
	});
    }
::reset(arg);
replace_program("/room/room");
}
