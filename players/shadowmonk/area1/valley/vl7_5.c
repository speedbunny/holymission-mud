inherit "/players/shadowmonk/inherit/room_area1";
#include "/players/shadowmonk/include/defs_area1.h"
 
void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    long_desc =
	"@@get_desc@@";
    dest_dir = ({ 
	VALL+"vl7_4", "north",
	VALL+"vl8_5", "east",
	VALL+"vl7_6", "south",
	VALL+"vl6_5", "west",
    }); 
}
