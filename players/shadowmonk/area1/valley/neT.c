inherit "/room/room";
#include "/players/shadowmonk/include/defs_area1.h"

void reset(int arg) {
    set_light(1);
    short_desc=   
	"Northeast tower..";
    long_desc=   
	"Northeast tower...\n";
    dest_dir=({ 
	VALL+"vl8_1", "south",
	VALL+"vl7_0", "west",
    });
    ::reset(arg);
    replace_program("room/room");
}
