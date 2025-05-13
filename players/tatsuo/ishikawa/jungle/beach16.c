inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"
reset(arg){
if(arg) return 1;
set_light(1);
short_desc="On the coast of Ishikawa";
long_desc=break_string(
	"You are on the western coast of Ishikawa.  The sun is setting "+
	"brilliantly over the sea, casting a hellish red glow on this "+
	"beach.  The tide washes over the black volcanic sand.  Everything "+
	"is dreadfully quiet.  Inland, to the east is a dense jungle, and "+
	"the coast continues north and southeast.  A large grey "+
	"rock protrudes above the waves, just off shore.\n",65);


items = ({
	"coast", short_desc,
	"sun","ARGH, you burn your retina",
	"grey rock","A large grey rock in the ocean. Maybe you could swim to it",
	"rock","A large grey rock in the ocean.  Maybe you could swim to it",
	"tide","The tide comes in and out, You get dizzy and fall down",
	"jungle","Most of the island is covered in jungle"
	"ishikawa","You are standing on it! What powers of perception",
	"sand","It is black, perhaps derived of basalt",
	});
property=({
	});
dest_dir=({
	IPATH+"beach18","north",
	IPATH+"beach14","southeast",
	IPATH+"jung50","east",
	});
}
void init(){
::init();
AA("_search","search");
AA("_swim","swim");
}
_search(){
write("You search around and find nothing.\n");
say(TPN+ " searches around.\n");
return 1;
}
_swim(){
write("Wait! That's not a rock! It's a WHALE!\n");
write("You are swallowed whole.\n");
say(TPN+" jumps in the water.\n");
MOVE("out to sea#players/tatsuo/ishikawa/whale");
return 1;
}
