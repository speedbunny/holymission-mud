inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg){
	set_light(1);
	short_desc= "A huge nest";
	long_desc= "You have entered a huge nest made out of trunks of trees and\n"+
	"long soft old reeds from the moat. Old egg shells lay about\n"+
	"the large nest with little slimey things crawling around them.\n"+
	"You now realize that this nest belongs to the huge moat monster,\n"+
	"Silthar!\n";
	items =
	({
	  "trunks","Huge old trees layed upon each other to make a nest for the babies",
	  "reeds","Old wet reeds are placed on the bottom of the nest",
	});
	clone_list = ({
	1, 1, "lizard", "players/tuppence/fortress/monster/lizard", 0,
	-1, 1, "sword", "players/tuppence/fortress/weapon/lsword", 0,
	2, 6, "baby", "players/tuppence/fortress/monster/baby", 0,
      });
    dest_dir =
    ({
      FROOM+"tun4","south",
      FROOM+"moat11","portal",
    });
}
::reset(arg);
replace_program("/room/room");
}
