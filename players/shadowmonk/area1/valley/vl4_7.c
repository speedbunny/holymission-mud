inherit "/players/shadowmonk/inherit/room_area1";
#include "/players/shadowmonk/include/defs_area1.h"
 
void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    long_desc =
	"@@get_desc@@";
    dest_dir = ({ 
	VALL+"vl4_6", "north",
	VALL+"vl5_7", "east",
	VALL+"vl4_8", "south",
	VALL+"vl3_7", "west",
    }); 
}
