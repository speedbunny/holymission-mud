inherit "/players/shadowmonk/inherit/room_area1";
#include "/players/shadowmonk/include/defs_area1.h"
 
void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    long_desc =
	"@@get_desc@@";
    dest_dir = ({ 
	VALL+"vl2_3", "north",
	VALL+"vl3_4", "east",
	VALL+"vl2_5", "south",
	VALL+"vl1_4", "west",
    }); 
}
