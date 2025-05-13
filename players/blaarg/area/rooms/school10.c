#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	clone_list = ({
		1,1,"teacher",MOB+"teacher",0,
		-1,1,"ruler",WEAPON+"ruler",0,
		2,8,"student",MOB+"student",0,
	});
	set_light(1);
	short_desc="Classroom",
	long_desc=
	    "This is one of the classrooms in the school. The teacher is\n"+
	    "involved in teaching the children Nihonese Calligraphy.\n"+
	    "She notices the interruption of your entrance, but\n"+
	    "apparently she does not care.\n";
	dest_dir=({
		AROOMS+"school7","west",
		 });
	items=({ 
		"desks","The desks are made of wood",
		"chalkboard","The chalkboard is made of slate, and has some "+
			      "markings you can't understand on it.\n",
      		});
	smell = "This place is a bit dusty";
    	::reset(arg);
	replace_program("room/room");
}
