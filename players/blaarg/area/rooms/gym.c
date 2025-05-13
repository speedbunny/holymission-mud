#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	set_light(1);
	short_desc="School Gym",
	long_desc=
		"The school's gymnasium is a large room, usually split\n"+
		"down the middle to segregate the males and females.\n"+
		"Since there are no classes inside now, the room is open.\n"+
		"To the north is the female dressing area, and to the\n"+
		"east is the male dressing area.\n";
	dest_dir=({
		AROOMS+"school4", "west",
		AROOMS+"fdress","north",
		AROOMS+"mdress","east",
		 });
	items=({
	    "floor","the floor is a bit dusty",
	    "female dressing area","The female dressing area is closed by "+
					"a pink door.",
	    "male dressing area","The male dressing area is closed by a "+
				    "blue door.",  
	      });
	smell = "The gym smells of dust and sweat";
	::reset(arg);
	replace_program("room/room");
}
