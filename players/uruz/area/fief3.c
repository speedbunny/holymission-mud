
inherit "/players/trout/area/random_peasant";
#include "/players/trout/defs.h"

reset(arg){
	if(arg) return;
	set_light(1);
	short_desc= "Grassy Field";	
	long_desc= "You are standing in a large grassy field in Tokugawa's "+
	"fief. A large river cuts through the land to your south. The area "+
	"looks very peaceful from here. \n";
	DD= ({ ZZ+"/fief2", "northeast" });
	items= ({ "river", "It is very swift here, and unusually dark for "+
		"a river"});
	::reset(arg);
	replace_program("room/room");
	}
