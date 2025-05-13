inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg){
	set_light(1);
	short_desc= "Lighted hallway";
	long_desc= "The cold breeze seems to have stopped now. Torches here are lit but\n"+
	"the flame seems to be grinning at you. Skulls hang on the walls with\n"+
	"some flesh still hanging on them. Bats hang on the walls staring\n"+
	"at you with their red and yellow eyes.\n";
	items =
	({
	  "torches","The torches are lit to light up the room",
	  "flame","It is grining at you!",
	  "skulls","They hang there from old battles won",
	});
clone_list = ({
1, 3, "bat", "players/tuppence/fortress/monster/bat", 0,
});
	dest_dir=
	({
	  FROOM+"hall5","south",
	  FROOM+"hall7","north",
	});
    }
::reset(arg);
replace_program("/room/room");
}
