inherit "/players/shadowmonk/inherit/room_area1";
#include "/players/shadowmonk/include/defs_area1.h"
 
void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    long_desc =
	"@@get_desc@@";
    dest_dir = ({ 
	VALL+"vl4_5", "north",
	VALL+"vl5_6", "east",
	VALL+"vl4_7", "south",
	VALL+"vl3_6", "west",
    }); 
}
