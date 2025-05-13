#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	set_light(1);
	short_desc="Tendo Parlour",
	long_desc=
	    "This is the parlour of the Tendo All-For-Nothing Dojo.\n"+
	    "In here, you can see a small table, some pads on the floor,\n"+
	    "and some pictures. To the West is the entry, to the East\n"+
	    "is the staircase, and to the North is the southeastern area\n"+
	    "of the practice room.\n";
	dest_dir=({
	    AROOMS+"tendoa01","west",
	    AROOMS+"tendoa03","east",
	    AROOMS+"tendoa17","north",
		 });
	items=({ 
	    "table","The table, made of oak, has a fine, dust-free finish",
	    "pads","The pads, embroidered in gold thread, make excellent\n"+
		   "seats. They look very comfortable",
	    "pictures","The pictures are of Tendo and his daughter, Akane",
	      });
	smell = "The parlour smells of fresh lotus flowers";
	::reset(arg);
	replace_program("room/room");
}