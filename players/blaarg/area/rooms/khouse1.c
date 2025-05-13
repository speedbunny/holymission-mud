#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	set_light(1);
	short_desc="Kunoh's House -- Entry",
	long_desc=
	    "This is the foyer of Kunoh's house. In the room is a window,"+
	    "a doorway leading north, a chair, a mat, and a bookshelf.\n";
	dest_dir=({
		AROOMS+"khouse2","north",
		AROOMS+"roada6","south",
		 });
	items=({
	    "window","You can see the road from here, and across the road"+
		     "is the high school",
	    "chair","The bamboo chair looks very comfortable",
	    "doorway","Kunoh's bedroom is just north of here",
	    "mat","The mat has some calligraphy on it",
	    "bookshelf","There are some books on it, but you can't read it", 
	      });
	smell = "The entry smells of Sandalwood";
	::reset(arg);
	replace_program("room/room");
}