inherit "/room/room";
#include "/players/shadowmonk/include/defs_area1.h"

int nmbguards;

void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    set_light(0);
    short_desc=   
	"Inside a cave.";
    nmbguards=2;
    long_desc=   
	"You are inside a cave. It is quite warm here, at the flow "+
	"seems to come from the north. @@guards@@ A path leads out "+
	"of the cave to the south to the forest. You see a red glow "+
	"to the north.\n";
    dest_dir=({ 
	VALL+"vl4_8", "north",
	ROAD+"r015", "south",
    });
    items=({ 
	"glow",
	    "You can not see what it is, but it was hold connection to "+
	    "to the heat.",
	"cave",
	    "A small cave at the base of the cliffside.",
    });
}

string guards() {
    switch(nmbguards) {
	case 2 :
	    return "You see two stone dragons standing face to face "+
		   "a little further north.";
	    break;
	case 1 :
	    return "You see a stone dragon standing a little further "+ 
		   "north.";
	    break;
	default :
	    return "You see four big footprints to the north of here.";
            break;
    }
    return "";
}

init() {
    ::init();
    add_action("north", "north");
}

int north() {
    if( nmbguards == 2 ) {
        TAL("The statues come to life and you see two young silver "+
	    "dragons, blocking your way to the north.\n");
        nmbguards=0;
	// clone those dragons
	return 1;
    }        
    if( nmbguards == 1 ) {
        TAL("A statue comes to life and you see a young silver "+
	    "dragon, blocking your way to the north.\n");
        nmbguards=0;
	// clone that dragon
	return 1;
    }        
    return ::move("north");
}
