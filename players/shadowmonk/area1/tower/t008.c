inherit "/room/room";
#include "/players/shadowmonk/include/defs_area1.h"

void reset(int arg) {
    set_light(1);
    short_desc=   
	"Inside the metallic tower..";
    long_desc=   
	"This is the west room on the fourth and final floor of this "+
	"magical tower. And i "+
	"dont feel like doing this description..It should be guarded by "+
	"a monster at the entrance of every room but havent figured out "+
	"what yet..\n";
    smell=
	"The fresh air is mingeled with that of roses.";
    dest_dir=({ 
	TOWR+"t004", "east",
    });
    ::reset(arg);
    replace_program("room/room");
}
