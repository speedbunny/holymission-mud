inherit "room/room";
#include "/players/tuppence/include/defs.h"
object wrat;
void reset(int arg) {
if(!arg){
set_light(0);
short_desc= "A dark tunnel";
long_desc= "There is water runing out of small holes on the walls. Rats run\n"+
	   "around at your feet nibbling at your shoes. Evil horned frogs\n"+
	   "look at you evilly from thier rocks. The glimmer of light is more\n"+
	   "Brighter now, you must be getting close to the end of this tunnel.\n"+
	   "Some dirt falls on your head, you wonder how long the ceiling will\n"+
	   "hold up.\n";
items =
({
"water","Little streams run down the walls from the holes",
"holes","Little holes with water runing out of them",
"rocks","Small multi-coloured rocks sit on the ground for the frogs to sit on",
"light","It has become brighter now",
"ceiling","Wow, this ceiling really isnt sturdy",
"dirt","It has just fallen on your head",
});
clone_list = ({
1, 1, "frog", "players/tuppence/fortress/monster/hfrog", 0,
-1, 1, "horn", "players/tuppence/fortress/weapon/fhorn", 0,
2, 2, "rat", "players/tuppence/fortress/monster/wrat", 0,
});
dest_dir=
({
FROOM+"tun1","south",
FROOM+"tun3","north",
});
}
::reset(arg);
replace_program("/room/room");
}
