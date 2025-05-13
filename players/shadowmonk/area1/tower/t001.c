inherit "/room/room";
#include "/players/shadowmonk/include/defs_area1.h"

void reset(int arg) {
    set_light(1);
    short_desc=   
	"Inside the metallic tower..";
    long_desc=   
	"This is the base floor of this magical tower. And i dont feel "+
	"like doing this description....\n";
    smell=
	"The fresh air is mingeled with that of roses.";
    dest_dir=({ 
	ROAD+"r011", "west",
	TOWR+"t002", "up",
    });
    ::reset(arg);
    replace_program("room/room");
}
