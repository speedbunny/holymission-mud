#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	set_light(1);
	short_desc="Tendo Office",
	long_desc=
	    "This is the Office of the Tendo All-For-Nothing Dojo.\n"+
	    "There is a desk, some bookshelves, and a few chairs here.\n"+
	    "To the East, there is a hall, and to the North is the\n"+ 
	    "southern area of the west dressing room.\n";
	dest_dir=({
		AROOMS+"tendoa14","east",
		AROOMS+"tendoa12","north",
		 });
	items=({ 
	    "desk","The desk is made of fine Mahogany, and has some\n"+
		   "papers on the blotter",
	    "papers","These are logs of different training sessions",
	    "bookshelves","There are some books on the wood shelves",
	    "books","The books are about karate, written by Tendo himself",
	    "chairs","The wood chairs are quite elegant",
	      });
	smell = "The office smells of drying ink";
	::reset(arg);
	replace_program("room/room");
}