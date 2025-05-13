inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg){
	set_light(1);
	short_desc= "Runed hallway";
	long_desc= "The walls have pictures painted on them. The walls and ceiling\n"+
	"seem to have gems placed in them. Dragon figurines are displayed\n"+
	"around the hallway. You can hear buzzing sounds around your head.\n";
	items =
	({
	  "walls","These are pictures of the great mage wars, you can almost sense the\n"+
	  "great magic they used",
	  "gems","Magic gems are placed in the walls to enhance the magic that goes\n"+
	  "on in these rooms",
	});
clone_list = ({
1, 1, "guard", "players/tuppence/fortress/monster/gmage", 0,
-1, 1, "robe", "players/tuppence/fortress/armour/grobe", 0,
2, 2, "fly", "players/tuppence/fortress/monster/dfly", 0,
});
	dest_dir=
	({
	  FROOM+"top1","south",
	  FROOM+"top4","east",
	  FROOM+"top3","west",
	});
    }
::reset(arg);
replace_program("/room/room");
}
