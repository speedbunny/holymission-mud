inherit "/players/shadowmonk/inherit/room_area1";
#include "/players/shadowmonk/include/defs_area1.h"
 
void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    long_desc =
	"@@get_desc@@";
    dest_dir = ({ 
	VALL+"vl1_6", "north",
	VALL+"vl2_7", "east",
	VALL+"vl1_8", "south",
	VALL+"vl0_7", "west",
    }); 
}
