inherit "/room/room";
#include "/players/shadowmonk/include/defs_area1.h"

void reset(int arg) {
    set_light(1);
    short_desc=   
	"Southeast tower..";
    long_desc=   
	"Southeast tower...\n";
    dest_dir=({ 
	VALL+"vl8_7", "north",
	VALL+"vl7_8", "west",
    });
    ::reset(arg);
    replace_program("room/room");
}
