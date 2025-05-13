inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg){
	set_light(1);
	short_desc= "Runed hallway";
	long_desc= "Fog hangs low around your feet. You can't see your feet because\n"+
	"the fog is so thick. You hope nothing else is down there. Your skin\n"+
	"tingles from the magic being used around you. More vines have somehow\n"+
	"grown on the ceiling and walls, but they are coloured black.\n";
	items =
	({
	  "fog","Thick grey fog covers the ground like a blanket",
	  "vines","The vines here seem to move around",
	});
	dest_dir=
	({
	  FROOM+"top2","west",
	  FROOM+"top6","east",
	  FROOM+"top5","north",
	});
    }
    ::reset(arg);
    replace_program("/room/room");
}
