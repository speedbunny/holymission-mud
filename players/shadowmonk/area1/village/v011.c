inherit "/room/room";
#include "/players/shadowmonk/include/defs_area1.h"

void reset(int arg) {
    set_light(1);
    short_desc=   
	"Inside Joyous..";
    long_desc=   
	"There are no houses here. It looks more like a playing "+
	"fields for kids. A grassfield is to the north on which "+
	"several childeren are playing ballgames. You're standing just "+
	"outside the circle of childeren that is sitting around an old "+
	"man who is telling his story.\n";
    smell=   	
	"You can smell cooked food and freshly washed clothes.";
    dest_dir=({ 
	VILL+"v010", "east",
    });
    items=({ 
	"field",
	  "Just a plain grassfield, which is comfortabl to sit on.",
	"childeren",
	    "They are all around the age of eight to twelve, and enjoying "+
	    "the story.",
    });
    clone_list = ({ 
	 1, 1, "oleman", MONS+"oleman", 0,
	 2, 8, "child", MONS+"child_f", 0, 
	 3, 20, "child", MONS+"child_m", 0 
    });
    ::reset(arg);
    replace_program("room/room");
}
