#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	clone_list = ({
		1,1,"shampoo",MOB+"shampoo",0,
	});
	set_light(1);
       short_desc="Shampoo's House",
	long_desc=
     "This is Shampoo's house...it's very quaint, but she likes\n"+
     "it quaint. There is an oriental rug adorning the hardwood\n"+
     "floor, and some traditional Japanese calligraphy on the walls.\n"+
     "Shampoo is here, and she's not too pleased that you are\n"+
     "disturbing her!\n";
	dest_dir=({
            AROOMS+"shshop1","east",
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