inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg){
	set_light(1);
	short_desc="The draw bridge";
	long_desc="You are now on the draw bridge. As you walk across you slip on\n"+
	"some slimy fungus. Be more careful.\n";
	dest_dir=
	({
	  FROOM+"gates","north",
	  FROOM+"entrance","south",
	});
	items=
	({
	  "fungus","There is some green and blue fungus here",
	});
    }
::reset(arg);
replace_program("/room/room");
}
