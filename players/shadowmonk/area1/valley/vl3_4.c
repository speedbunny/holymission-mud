inherit "/players/shadowmonk/inherit/room_area1";
#include "/players/shadowmonk/include/defs_area1.h"
 
void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    long_desc =
	"@@get_desc@@";
    dest_dir = ({ 
	VALL+"vl3_3", "north",
	VALL+"mmT", "east",
	VALL+"vl3_5", "south",
	VALL+"vl2_4", "west",
    }); 
}
