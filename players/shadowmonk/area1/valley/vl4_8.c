inherit "/players/shadowmonk/inherit/room_area1";
#include "/players/shadowmonk/include/defs_area1.h"
 
void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    long_desc =
	"@@get_desc@@ There is a small cave enterance "+
	"to the south.\n";
    dest_dir = ({ 
	VALL+"vl4_7", "north",
	VALL+"vl5_8", "east",
	ROAD+"r016", "south",
	VALL+"vl3_8", "west",
    }); 
}
