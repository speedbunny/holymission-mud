inherit "/players/shadowmonk/inherit/room_area1";
#include "/players/shadowmonk/include/defs_area1.h"
 
void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    long_desc =
	"@@get_desc@@";
    dest_dir = ({ 
	VALL+"vl7_6", "north",
	VALL+"vl8_7", "east",
	VALL+"vl7_8", "south",
	VALL+"vl6_7", "west",
    }); 
}
