inherit"room/room";
reset(arg)	{
::reset(arg);
if(arg)return;

set_light(1);
short_desc=(" a room with a white marble floor\n.");
long_desc=("a room with a white marble floor\n.");
dest_dir=({
	"players/starslayer/c1/d2","north",
	"players/starslayer/c1/e1","east",
	"players/starslayer/c1/c1","west"
	});
items=({
	"a smoothly polished black marble floor","floor"
	});
		}
