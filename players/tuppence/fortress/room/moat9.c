inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg) {
	set_light(0);
	short_desc= "Moldy moat";
	long_desc= "Lilypads float around you with pink and white flowers. You\n"+
	"can hear frogs ribbiting around you. Ivy, crawling with insects, grows\n"+
	"up and down the walls. Tall cattails, as high as you, stand along the\n"+
	"waters edge. The moat is getting deeper the further you go.\n";
	items=
	({
	  "lilypads","They have pretty pink and white flowers, along with cute\n"+
	  "little frogs",
	  "ivy","It almost seems to move long with you",
	  "cattails","Tall cattails grow here",
	});
clone_list = ({
1, 2, "sprite", "players/tuppence/fortress/monster/wsprite", 0,
-1, 1, "helmet", "players/tuppence/fortress/armour/crown", 0,
2, 1, "pixie", "players/tuppence/fortress/monster/pixie", 0,
-2, 1, "dust", "players/tuppence/fortress/weapon/dust", 0,
});
	dest_dir=
	({
FROOM+"moat8","south",
FROOM+"moat10","north",
	});
    }
::reset(arg);
replace_program("/room/room");
}
