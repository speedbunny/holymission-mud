inherit "/players/shadowmonk/inherit/room_area1";
#include "/players/shadowmonk/include/defs_area1.h"
 
void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    long_desc =
	"@@get_desc@@";
    dest_dir = ({ 
	VALL+"vl0_1", "north",
	VALL+"vl1_2", "east",
	VALL+"vl0_3", "south",
    }); 
}
