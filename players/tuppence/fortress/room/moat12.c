inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg) {
	set_light(0);
	short_desc= "Moldy moat";
	long_desc= "Thorn bushes grow in the moat. Dont go to close, you dont want\n"+
	"to get pricked by those thorns. Willow trees grow along the waters\n"+
	"edge, making a great home for diffrent birds around the area. Small\n"+
	"yellow flowers have grown on the fortress's walls here. You can\n"+
	"hear the most beautiful songs from the birds around you.\n";
	items =
	({
	  "bushes","Big thorn bushes grow around you here",
	  "trees","Big beautiful willow trees grow around the sides of the moat",
	  "flowers","Little yellow flowers have attached themselves to the walls here",
	});
clone_list = ({
1, 1, "alligator", "players/tuppence/fortress/monster/alligator", 0,
2, 2, "frog", "players/tuppence/fortress/monster/bfrog", 0,
-1, 1, "skin", "players/tuppence/fortress/armour/askin", 0,
});
	dest_dir=
	({
	FROOM+"moat11","east",
	FROOM+"moat13","west",
	});
    }
::reset(arg);
replace_program("/room/room");
}
