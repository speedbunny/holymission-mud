inherit"room/room";
#include	"/players/starslayer/defs.h"
reset(arg)	{
::reset(arg);
if(arg)return;

set_light(1);
short_desc=("a room with a black marble floor\n.");
long_desc=("a room with a black marble floor\n.");
dest_dir=({
	"CP/c2","north",
	"CP/d1","east",
	"CP/b1","west"
	});
items=({
	"a smoothly polished black marble floor","floor"
	});
		}
