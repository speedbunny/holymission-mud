inherit "/players/shadowmonk/inherit/room_area1";
#include "/players/shadowmonk/include/defs_area1.h"
 
void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    long_desc =
	"@@get_desc@@";
    dest_dir = ({ 
	VALL+"vl4_2", "north",
	VALL+"vl5_3", "east",
	VALL+"mmT", "south",
	VALL+"vl3_3", "west",
    }); 
}
