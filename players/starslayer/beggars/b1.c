inherit"room/room";
reset(arg)	{
::reset(arg);
if(arg)return;
set_light(0);
short_desc= "a dark alley";
long_desc="You are in a dark alley full of rubbish.\n";

dest_dir =({
	"players/starslayer/workroom","west",
	"players/starslayer/beggars/b2","east"
	});
items	=({
"rubbish","its putrid, horrible and possible alive.searching that would make you ill.\n"
	});
}
