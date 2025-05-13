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
1, 1, "barracuda", "players/tuppence/fortress/monster/bfish", 0,
2, 1, "ivy", "players/tuppence/fortress/monster/ivy", 0,
-1, 1, "teeth", "players/tuppence/fortress/weapon/bteeth", 0,
});
	dest_dir=
	({
	FROOM+"moat6","south",
	FROOM+"moat8","north",
	});
    }
::reset(arg);
replace_program("/room/room");
}
