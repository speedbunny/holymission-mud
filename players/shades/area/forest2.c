inherit "room/room";
#include "/players/shades/def.h"

reset(tick){
	if(tick) return;
	set_light(1);
	short_desc= "forest";
	long_desc= "This is a forest with many large trees. Despite the fact"+
		   " that there is light being let in, there are still many "+
                   "dark shadows.\n";

dd=({jj+"/forest1", "west",
     jj+"/forest4", "east",
     jj+"/forest8", "north"});
	}
