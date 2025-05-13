inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg){
	set_light(1);
	short_desc="Guarded gates to Haden";
	long_desc="Troll guards, guard the gates to the fortress Haden. They seem mad\n"+
	"that you are here. Maybe you'd better leave before they attack you.\n"+
	"The gates of Haden seem to radiate evil and death to all those who\n"+
	"enter.\n";
	items=
	({
	  "gates","You sense death and power before these gates",
	});
clone_list = ({
1, 2, "guard", "players/tuppence/fortress/monster/tguard", 0,
});
	dest_dir=
	({
	FROOM+"hall1","north",
	  FROOM+"bridge","south",
	});
    }
::reset(arg);
replace_program("/room/room");
}
