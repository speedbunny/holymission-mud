inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg) {
	set_light(0);
	short_desc= "Dark moat";
	long_desc= "Tiny deer hoofprints surround the moats edge. You hope the deer\n"+
	"didnt drink from that muddy water. You are freezing from standing\n"+
	"in the water so long. You'd better get out before you catch yourself\n"+
	"a cold. Strange multi-coloured moss grows on the fortress walls.\n"+
	"Dead flowers and plants lay on top of the moat. The moat's\n"+
	"water was too poisonus for the plants. The moat smells terrible here.\n";
	items =
	({
	  "hoofprints","Prints made by a tiny deer, checking out the moat",
	  "moss","Strange moving moss creeping on the walls",
	  "flowers","They are dead",
	  "plants","They are also dead",
	});
clone_list = ({
1, 1, "wrat", "players/tuppence/fortress/monster/wrat", 0,
2, 1, "pixie", "players/tuppence/fortress/monster/pixie", 0,
-2, 1, "dust", "players/tuppence/fortress/weapon/dust", 0,
});
	dest_dir=
	({
	  FROOM+"moat16","north",
	  FROOM+"moat18","south",
	});
    }
::reset(arg);
replace_program("/room/room");
}
