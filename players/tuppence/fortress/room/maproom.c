inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg){
	set_light(0);
	short_desc = "The map room";
	long_desc= "Wow! There are tons of maps and scrolls in this room. This must be\n"+
	"where they store all the maps and plans for their battles. To bad\n"+
	"you can't read the ancient writing on them. All the maps and scrolls\n"+
	"are stored on shelves and chests.\n";
	items =
	({
	  "maps","Maps of the world and kingdoms",
	  "scrolls","Ancient scrolls, you wish you knew what they said",
	  "chests","chests containing the maps and scrolls",
	  "shelves","Maps and scrolls lay on them",
	});
	dest_dir =
	({
	  FROOM+"plroom","west",
	});
    }
::reset(arg);
replace_program("/room/room");
}
