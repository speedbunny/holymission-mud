inherit "/room/room";
#include "/players/shadowmonk/include/defs_area1.h"

void reset(int arg) {
    set_light(1);
    short_desc=   
	"Inside Joyous..";
    long_desc=   
	"There is nobody inside this church at the moment. It is "+
	"not really big, but big enough to host the people of "+
	"Joyous. The wooden benches stand neatly in rows, and look "+
	"very tidy, as does everything else in this town.\n";
    smell=   	
	"You can smell cooked food and freshly washed clothes.";
    dest_dir=({ 
	VILL+"v004", "west",
    });
    items=({ 
	"benches",
	  "Long wooden benches, which look very clean.",
    });
    ::reset(arg);
    replace_program("room/room");
}
