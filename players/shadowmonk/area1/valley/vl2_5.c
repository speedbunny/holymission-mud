inherit "/players/shadowmonk/inherit/room_area1";
#include "/players/shadowmonk/include/defs_area1.h"
 
void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    long_desc =
	"@@get_desc@@";
    dest_dir = ({ 
	VALL+"vl2_4", "north",
	VALL+"vl3_5", "east",
	VALL+"vl2_6", "south",
	VALL+"vl1_5", "west",
    }); 
}
