inherit "/players/shadowmonk/inherit/room_area1";
#include "/players/shadowmonk/include/defs_area1.h"
 
void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    long_desc =
	"@@get_desc@@";
    dest_dir = ({ 
	VALL+"vl1_0", "north",
	VALL+"vl2_1", "east",
	VALL+"vl1_2", "south",
	VALL+"vl0_1", "west",
    }); 
}
