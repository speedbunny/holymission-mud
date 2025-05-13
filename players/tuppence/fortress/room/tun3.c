inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg){
	set_light(0);
	short_desc= "A dark tunnel";
	long_desc= "The light at the end of the tunnel looks more like a opening now\n"+
	"and it looks worth the trip. Some more water rats are crawling up\n"+
	"the walls here. You are almost knee deep in water now, you hope it\n"+
	"doesnt get any higher. You can hear high pitched growling coming\n"+
	"from the opening ahead.\n";
	items =
	({
	  "light","Looks like the end of the tunnel",
	  "water","Your knee high in it, better hope it doesnt get any higher",
	});
clone_list = ({
1, 2, "spider", "players/tuppence/fortress/monster/spider", 0,
-1, 1, "web", "players/tuppence/fortress/armour/web", 0,
2, 1, "goblin", "players/tuppence/fortress/monster/goblin", 0,
-2, 1, "sword", "players/tuppence/fortress/weapon/gsword", 0,
-2, 1, "helmet", "players/tuppence/fortress/armour/ghelmet", 0,
});
	dest_dir=
	({
	  FROOM+"tun2","south",
	  FROOM+"tun4","north",
	});
    }
::reset(arg);
replace_program("/room/room");
}
