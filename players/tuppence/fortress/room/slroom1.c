inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg){
	set_light(1);
	short_desc = "Sleeping guards";
	long_desc = "You have entered a room with lots of beds. This must be\n"+
	"where the guards sleep. There are a few monsterous things laying in the\n"+
	"beds snoring loudly, but you arent sure what they are since they\n"+
	"are so ugly! Uh oh, you seem to have woken one up. You better run.\n";
	items = 
	({
	  "beds","they are small but seem comfortable",
	});
clone_list = ({
1, 1, "guard", "players/tuppence/fortress/monster/slguard", 0,
});
	dest_dir =
	({
	  FROOM+"hall3","east",
	});
    }
::reset(arg);
replace_program("/room/room");
}
