inherit "/room/room";
#include "/players/shadowmonk/include/defs_area1.h"

void reset(int arg) {
    set_light(1);
    short_desc=   
	"middle tower..";
    long_desc=   
	"middle tower...\n";
    dest_dir=({ 
	VALL+"vl4_3", "north",
	VALL+"vl5_4", "east",
	VALL+"vl4_5", "south",
	VALL+"vl3_4", "west",
    });
    ::reset(arg);
    replace_program("room/room");
}
