inherit "/players/shadowmonk/inherit/room_area1";
#include "/players/shadowmonk/include/defs_area1.h"
 
void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    long_desc =
	"@@get_desc@@";
    dest_dir = ({ 
	VALL+"vl2_0", "north",
	VALL+"vl3_1", "east",
	VALL+"vl2_2", "south",
	VALL+"vl1_1", "west",
    }); 
}
