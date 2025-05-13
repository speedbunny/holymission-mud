#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	clone_list = ({
		1,1,"tendo",MOB+"tendo",0,
	});
	set_light(1);
	short_desc="Tendo Dojo--Tendo's Bedroom",
	long_desc=
	   "You have entered the bedroom of the master of this house,\n"+
	   "Tendo.  He watches you look around intently.  Also in\n"+
           "the room, there is a bed, a dresser, a closet, a window, and\n"+
           "some pictures.\n";
	dest_dir=({
	   AROOMS+"tendoc02","east",
	   AROOMS+"tendoc04","south",
		 });
	items=({ 
	   "bed","A very beautiful bed, with the covers embroidered in gold",
	   "window","At this height, you can see all of the village",
	   "dresser","Beautiful hardwood, hand carved. You cannot open it",
	   "picture","A picture of Akane, and a picture of Ranma and Akane",
	   "closet","The closet contains Tendo's more fasionable kimonos",
	   });
	smell = "Tendo's room smells of Sandalwood Incense";
	::reset(arg);
	replace_program("room/room");
}