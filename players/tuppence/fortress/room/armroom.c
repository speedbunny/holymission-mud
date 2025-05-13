inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg){
	set_light(1);
	short_desc= "The armour hold";
	long_desc= "This is where the soldiers store their armour when not in battle.\n"+
	"The armour here looks old and is in need of repair. Maybe some\n"+
	"of the soldiers have just gotten back from a great battle.\n";
	items =
	({
	  "armour","They are all torn and bloody",
	});
	dest_dir =
	({
	  FROOM+"hall1","east",
	});
    }
::reset(arg);
replace_program("/room/room");
}
