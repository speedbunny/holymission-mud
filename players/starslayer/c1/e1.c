inherit"room/room";
#define CP players/starslayer/c1
reset(arg)	{
::reset(arg);
if(arg)return;

set_light(1);
short_desc=("a room with a black marble floor\n.");
long_desc=("a room with a black marble floor\n.");
dest_dir=({
	"players/starslayer/c1/e2","north",
	"players/starslayer/c1/f1","east",
	"players/starslayer/c1/d1","west",
	});
items=({
	"a smoothly polished black marble floor","floor"
	});
		}
