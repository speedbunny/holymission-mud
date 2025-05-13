inherit "/room/room";
#include "/players/shadowmonk/include/defs_area1.h"

void reset(int arg) {
    set_light(1);
    short_desc=   
	"In front of the metallic tower..";
    long_desc=   
	"You're standing in front of a huge metallic tower. The entrance is"+
	" right in front of you. The doors are made out of some kind of "+
	"metal, and about ten feet high. A dragon is carved on both of the "+
	"doors. The doors are open and an inviting smell of roses is coming"+
	" from the inside.\n";
    smell=
	"The fresh air is mingeled with that of roses.";
    dest_dir=({ 
	TOWR+"t001", "east",
	ROAD+"r010", "west",
    });
    items=({ 
	"dragons",
	    "It resembles a huge dragon, but one with a friendly smile.",
	"doors",
	    "They are made out of pure silver.",
	"tower",
	    "The metal used for this tower is .. pure ... silver....",
    });
    ::reset(arg);
    replace_program("room/room");
}
