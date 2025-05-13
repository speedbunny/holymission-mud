#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	clone_list = ({
		1,1,"genma",MOB+"genma",0,
	});
	set_light(1);
	short_desc="Tendo Dojo--Genma's Bedroom",
	long_desc=
	    "This is Genma's bedroom. He doesn't look too happy that you\n"+
	    "are disturbing his privacy, but after a few seconds he gets\n"+
	    "used to your presence. There is a bed, a window, a mat on\n"+
	    "the floor, a dresser, and a picture on the dresser.\n";
	dest_dir=({
	    AROOMS+"tendoc03","west",
	    AROOMS+"tendoc01","south",
		 });
	items=({ 
	   "bed","A pretty nondescript bed, however it is covered with\n"+
		 "panda fur",
	   "window","At this height, you can see all of the village",
	   "mat","A pretty average mat",
	   "dresser","Wood, but Genma doesn't like you nosing around there",
	   "picture","A picture of Ranma and Akane", 
	   });
	smell = "Genma's room smells of panda fur";
	::reset(arg);
	replace_program("room/room");
}