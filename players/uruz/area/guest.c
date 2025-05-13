inherit "/players/trout/area/random_guard";
#include "/players/trout/defs.h"
	
reset(arg){
	if(arg) return;
	set_light(1);
	short_desc="Guest Quarters";
	long_desc="This is the guest room of Honno Ji. An elaborate canopy "+

	"bed boasts the wealth of Daimyo Tokugawa. A large window offers a "+
	"view to the outer ward. Several dressers are placed against the "+
	"northern wall. You've never seen a guest room this nice! \n";

	DD= ({ ZZ+"/recept", "west" });

	items= ({ "dresser", "A beautiful mohagany dresser, filled with "+			"silk clothes",
		"bed", "A king size bed with trouts on the sheets" });
	::reset(arg);	
	replace_program("room/room");
	}
