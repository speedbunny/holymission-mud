
inherit "room/room";
#include "/players/trout/defs.h"

reset(arg){
	if(arg) return;
	set_light(1);

	short_desc= "Shrine";
	long_desc= "As you walk through the entrance here, the smell of "+
	"burning incense assaults your nose. A modest altar stands near the "+
	"far end, lined with candles. A painting is mounted behind the altar"+
	" on the wall. It would appear that this is some sort of shrine. \n";
	DD= ({ ZZ+"/dojo4", "west" });
	items= ({ "painting", "It depiscts the japanese religious realm of "+
	"the eight million gods",
		"candle", "It gives off a strong frangrance as well as "+
		"light" });
	clone_list = ({1, RAN(3), "student", MM+"/student", 0});
	::reset(arg);
	replace_program("room/room");
		}
