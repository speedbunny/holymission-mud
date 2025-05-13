inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
if(!arg){
set_light(1);
short_desc= "Clerics chamber";
long_desc= "This is where the clerics of the Haden rest and practice their\n"+
	   "magic. These evil clerics worship all that is evil and hateful\n"+
	   "and they dont seem pleased that you have entered their chambers\n"+
	   "either. You had better leave before they kill you.\n";
items =
({
"chambers","It is decorated in earth colours",
});
clone_list = ({
1, 3, "cleric", "players/tuppence/fortress/monster/ecleric", 0,
-1, 1, "ring", "players/tuppence/fortress/armour/cring", 0,
});
dest_dir=
({
FROOM+"top4","south",
});
}
::reset(arg);
replace_program("/room/room");
}
