inherit "/players/shadowmonk/inherit/room_area1";
#include "/players/shadowmonk/include/defs_area1.h"
 
void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    long_desc =
	"@@get_desc@@";
    dest_dir = ({ 
	VALL+"vl1_1", "north",
	VALL+"vl2_2", "east",
	VALL+"vl1_3", "south",
	VALL+"vl0_2", "west",
    }); 
}
