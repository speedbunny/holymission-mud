inherit "/players/shadowmonk/inherit/room_area1";
#include "/players/shadowmonk/include/defs_area1.h"
 
void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    long_desc =
	"@@get_desc@@";
    dest_dir = ({ 
	VALL+"vl5_5", "north",
	VALL+"vl6_6", "east",
	VALL+"vl5_7", "south",
	VALL+"vl4_6", "west",
    }); 
}
