inherit "players/trout/area/random_peasant";
#include "/players/trout/defs.h"

reset(arg){
	if(arg) return;
	set_light(1);
	short_desc= "Path to Tokugawa's Fief";
	long_desc= "This path leads directly to Daimyo Tokugawa's fief. It "+
	"is well trodden by the vassals under Daimyo Tokugawa. The path "+
	"continues south.\n";
	DD= ({ ZZ+"/fief2", "south",
		ZZ+"/rice5", "southwest",
         "/players/patience/ezo/meadow26","north"});
	items= ({"path", "A simple dirt path"});
	::reset(arg);
	replace_program("room/room");
	}
