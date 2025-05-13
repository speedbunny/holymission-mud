#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	clone_list = ({
		1,1,"akane",MOB+"akane",0,
	});
	set_light(1);
	short_desc="Tendo Dojo--Akane's Bedroom",
	long_desc=
	    "This is Akane's bedroom. It seems like you have caught her\n"+
	    "at a pretty inopportune time, and she yells at you for\n"+
	    "startling her. She looks very impatient and starts tapping\n"+
	    "her foot, mumbling various profanities under her breath. In\n"+
	    "the room, there is a bed, a dresser, a closet, a window, and\n"+
	    "some pictures.\n";
	dest_dir=({
	    AROOMS+"tendoc05","northeast",
	    AROOMS+"tendoc03","north",
		 });
	items=({ 
	   "bed","A very beautiful bed, with the covers embroidered in gold",
	   "window","At this height, you can see all of the village",
	   "dresser","Beautiful hardwood, hand carved. You cannot open it",
	   "picture","A picture of Ranma, and a picture of Tendo", 
	   "closet","The closet contains Akane's formal outfits",
	   });
	smell = "Akane's room smells of fresh lotus flowers";
	::reset(arg);
	replace_program("room/room");
}