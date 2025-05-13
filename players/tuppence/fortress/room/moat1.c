inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg) {
	set_light(0);
	short_desc= "Moldy moat";
	long_desc= "As you jump into the moat, black mud splashes your armour and\n"+
	"gives you a weird smell. You can feel something swimming and\n"+
	"nibbling at your legs and feet. The moat water starts to bubble\n"+
	"around you. Mold and fungus grow on the top of the water and the\n"+
	"fortress walls. Long black and green reeds grow along the waters\n"+
	"edge. The reeds poke and cut at you as you walk by them.\n";
	items =
	({
	  "water","It is black and sticky",
	  "mold","Green and brown mold grows on the walls and water",
	  "fungus","Green and yellow fungus grows around you",
	  "reeds","Black and green reeds grow by the water side, they seem to have\n"+
	  "something moving around in there but you cant see what",
	});
	clone_list = ({
	  1, 2, "slug", "players/tuppence/fortress/monster/slug", 0,
	  -1, 1, "slime", "players/tuppence/fortress/armour/slime", 0,
	});
	dest_dir=
	({
	  FROOM+"entrance","up",
	  FROOM+"moat2","east",
	});
    }
    ::reset(arg);
    replace_program("/room/room");
}
void init () {
    ::init();
    this_player()->set_smell(" Smells like mold and meldew. EWWW");

}
