inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg){
	set_light(1);
	short_desc= "The weapons hold";
	long_desc= "This is where the soldier's weapons are stored when not in battle\n"+
	"or training. There are racks and racks of different types of weapons.\n"+
	"You think you have never seen so many weapons in one room before.\n";
	items = 
	({
	  "racks","There are alot of different weapons on them",
	  "weapons","You see bows, long swords and other different weapons",
	});
	dest_dir =
	({
	  FROOM+"hall1","west",
	});
    }
::reset(arg);
replace_program("/room/room");
}
