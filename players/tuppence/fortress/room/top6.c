inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg){
	set_light(1);
	short_desc= "A firey room";
	long_desc= "The heat is very intense in this part of the fortress.\n"+
	"Little red and orange flames dance around the room in front\n"+
	"of you. Bright red and yellow flowers grow on the walls and\n"+
	"ceiling, they dont seem to be bothered by all the fire here.\n"+
	"You can feel a strong ghostly presence hanging around the room.\n";
	items=
	({
	  "flames","Small crackling flames dance around you",
	  "flowers","You dont think you have ever seen such flowers before",
	});
	clone_list = ({
	  1, 2, "spirit", "players/tuppence/fortress/monster/fspirit", 0,
	  -1, 1, "belt", "players/tuppence/fortress/armour/fbelt", 0,
	});
	dest_dir=
	({
	  FROOM+"top4","west",
	  FROOM+"top7","east",
	});
    }
    ::reset(arg);
    replace_program("/room/room");
}
