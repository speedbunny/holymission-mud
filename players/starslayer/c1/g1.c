inherit"room/room";
reset(arg)	{
::reset(arg);
if(arg)return;

set_light(1);
short_desc=("a room with a black marble floor\n.");
long_desc=("a room with a black marble floor\n.");
dest_dir=({
	"players/starslayer/c1/a2","north",
	"players/starslayer/c1/b1","east"
	});
items=({
	"a smoothly polished black marble floor","floor"
	});
		}
