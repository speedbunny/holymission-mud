inherit "/players/shadowmonk/inherit/room_area1";
#include "/players/shadowmonk/include/defs_area1.h"
 
void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    long_desc =
	"@@get_desc@@";
    dest_dir = ({ 
	VALL+"vl6_3", "north",
	VALL+"vl7_4", "east",
	VALL+"vl6_5", "south",
	VALL+"vl5_4", "west",
    }); 
}
