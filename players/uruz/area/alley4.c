inherit "room/room";
#include "/players/trout/defs.h"

reset(arg) {
	if(arg) return;
	set_light(1);
	short_desc= "A Bloody Alley";
	long_desc= "The upper portion of the alley opens up, letting in just "+
	"enought light to let you see the blood strayed all over the walls "+
	"and floor. The blood appears fresh. The sounds of battle grow even "+
	"louder, as your heart starts to pound. The alley branches east, and"+
	" continues south. \n";
	DD= ({ ZZ+"/alley5", "east",
		ZZ+"/alley3", "south" });
	items= ({ "blood", "You almost lose your lunch just looking at it!"});
	::reset(arg);
	replace_program("room/room");
	}
