inherit "room/room";
#include "/players/trout/defs.h"

reset(arg){
	if(arg) return;
	set_light(1);
	short_desc= "The Library";
	long_desc="This room is filled from top to bottom with books. Stacks"+
	" of them form isles to walk through. Most of the books have japanese"+
	" titles, but a few in english catch your eye. A tiny window is the "+
	"only source of light. \n";
	DD= ({ ZZ+"/tearoom", "west" });
	items= ({ "books", "They're everywhere!" });
	::reset(arg);
	replace_program("room/room");
	}
