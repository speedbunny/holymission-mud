inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg){
	set_light(1);
	short_desc= "Runed hallway";
	long_desc= "Globes of light float above your head. You can sense evil magic\n"+
	"around you. The walls have carved runes in them, too bad you can't\n"+
	"understand them.\n";
	items=
	({
	  "globes","Big blue and yellow globes of light",
	  "runes","You can't read it, they are too ancient",
	});
	dest_dir=
	({
	  FROOM+"hall7","down",
	  FROOM+"top2","north",
	});
    }
::reset(arg);
replace_program("/room/room");
}
