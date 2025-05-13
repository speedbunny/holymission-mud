#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	clone_list = ({
		1,1,"uykio",MOB+"uykio",0,
	});
	set_light(1);

        short_desc="Uykio's House",

	long_desc=

		"Uykio's house serves as her sanctuary away from her shop. She "+
		"usually doesn't like company, so please don't dawdle in here "+
		"too long.\n";

	dest_dir=({

            AROOMS+"roadb2","north",
            AROOMS+"ushop","east",
		 });

	items=({ 
	   "bed","A very beautiful hardwood bed, with fine silk covers",
	   "window","At this height, you can see all of the village",
	   "dresser","Beautiful hardwood, hand carved. You cannot open it",
	   "picture","A picture of Akane, and a picture of Genma", 
	   });
	::reset(arg);
	replace_program("room/room");
}