inherit "room/room";
#include "/players/trout/defs.h"

reset(arg){
	if(arg) return;
	set_light(1);
	short_desc="A Pocket Dimension";
	long_desc="You are standing a barren plain. The skies above you "+
	"are filled with dark clouds, passing by with high speeds. A sound "+
	"of rushing wind is ever present here. It appears that the plain "+
	"go on for miles!\n";
	items= ({ "clouds", "Dark clouds, that look extremely distorted",
		"cloud", "A dark cloud that looks extremely distorted",
		"plain", "A desolate plain with signs of life" });
	::reset(arg);
	replace_program("room/room");
	}
