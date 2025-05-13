inherit "/players/trout/area/random_guard";
#include "/players/trout/defs.h"


reset(arg){
	if(arg) return;

	set_light(1);
	short_desc="Reception Room";
	long_desc="This is the grand reception room of Honno Ji. In the "+
	  "center of the room is a large table. Huge pillows surround the "+
	" table, offering a comfortable place to sit. Paintings and scrolls "+
	"of japanese poetry occupy the walls. Doors are visible at the south"+
	", east, and west ends. \n";
	DD= ({ ZZ+"/hall2", "north",
		ZZ+"/kitchen", "west",
		ZZ+"/guest", "east",

		ZZ+"/tearoom", "south" });
	items= ({ "table", "A lovely oak table standing only 2 feet high",
		"pillows", "They beg you to start a pillow war",
		"paintings", "Most depict battle scenes",
		"poetry", "A man's life is fifty years\n"+
			"In the universe what is there but dreams and "+
			"illusion?\n Is there any born who does not "+
			"die?\n                  -Oda Nobunga"});
	::reset(arg);
	replace_program("room/room");
	}
