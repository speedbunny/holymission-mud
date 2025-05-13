inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg){
	set_light(1);
	short_desc= "Lighted dungeon hallway";
	long_desc= "The dungeon hallway is lit up by stands standing next to the\n"+
	"walls. There are signs that rats have been here all over the place.\n"+
	"You can hear screaming from the west, maybe you should go see what's\n"+
	"going on in there?\n";
	items =
	({
	  "stands","Stands with diffrent oils lit to light up the hallways",
	});
clone_list = ({
1, 2, "rat", "players/tuppence/fortress/monster/rat", 0,
-1, 2, "cheese", "players/tuppence/fortress/item/cheese", 0,
});
	dest_dir=
	({
	FROOM+"tortroom","west",
	FROOM+"dun6","north",
	  FROOM+"dun4","south",
	  FROOM+"cell3","east",
	});
    }
::reset(arg);
replace_program("/room/room");
}
