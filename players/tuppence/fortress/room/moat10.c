inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg) {
	set_light(0);
	short_desc= "Moldy moat";
	long_desc= "Big boulders sits in the moat making a great home for some fungus.\n"+
	"As you walk through the moat, the water seems to rise alittle and\n"+
	"pull you under the water. But before you go down, you catch yourself\n"+
	"on a floating branch. Slime hangs down from the walls of the fortress.\n"+
	"A sparrow flys overhead, squawking at you, as if he was trying to tell\n"+
	"you something.\n";
	items =
	({
	  "boulders","Big boulders lay around with some fungus crawling on them",
	  "water","It trys to pull you under",
	  "branch","It floats on top of the water, lucky for your it can hold you weight",
	  "slime","Black slime drips into the moat",
	  "sparrow","This little bird seems to be worried about something up ahead",
	});
clone_list = ({
1, 1, "goblin", "players/tuppence/fortress/monster/goblin", 0,
-1, 1, "sword", "players/tuppence/fortress/weapon/gsword", 0,
-1, 1, "helmet", "players/tuppence/fortress/armour/ghelmet", 0,
});
	dest_dir=
	({
	FROOM+"moat9","south",
	FROOM+"moat11","west",
	});
    }
::reset(arg);
replace_program("/room/room");
}
