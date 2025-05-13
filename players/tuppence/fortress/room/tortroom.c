inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
if(!arg){
set_light(1);
short_desc= "The torture room";
long_desc= "Fear runs through you as you walk into this room of torture.\n"+
	   "Chains and shackles are hanging off the walls, a couple have\n"+
	   "prisoners in them. A guard stands here whipping the prisoners\n"+
	   "till they tell him what he wants to know. A big table stands\n"+
	   "in the middle of the room, probably where they chain up the poor\n"+
	   "prisoners to find out information about their enemies. Blood and\n"+
	   "flesh cover the room. The guard that stands here torturing the\n"+
	   "prisoners seems to enjoy his work.\n";
items =
({
"chains","They are here to chain up the prisoners",
"shackles","To keep the prisoners standing up next to the walls",
"table","A big wooden table with chains and knives on it, blood drips off it",
"blood","Most likely from the prisoners",
"flesh","Flesh from the prisoners that have been tortured and died here",
});
clone_list = ({
1, 1, "guard", "players/tuppence/fortress/monster/ttguard", 0,
-1, 1, "whip", "players/tuppence/fortress/weapon/whip", 0,
2, 2, "prisoner", "players/tuppence/fortress/monster/prisoner", 0,
-2, 1, "shackle", "players/tuppence/fortress/armour/shackles", 0,
});
dest_dir =
({
FROOM+"dun5","east",
});
}
::reset(arg);
replace_program("/room/room");
}
