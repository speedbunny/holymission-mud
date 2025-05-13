#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
	set_light(1);
	short_desc="Tendo Entry",
	long_desc=
	    "This is the entry room of the Tendo All-For-Nothing Dojo.\n"+
	    "To the West, there is a hall, to the East, a parlor, and to\n"+
	    "the North is the south central area of the first floor\n"+
	    "practice room.\n\n\nThere is a sign here.\n";
	dest_dir=({
		AROOMS+"tendoa14","west",
		AROOMS+"tendoa02","east",
		AROOMS+"tendoa16","north",
		 });
	items=({ 
	    "sign","Beware: Do not Attempt to attack anyone over White\n"+
		   "Belt rank unless you are above 18th lvl. Do not attempt\n"+
		   "to attack anyone on Floor III until at least 27th lvl.\n"+
		   "Blaarg will not assume any responsibility for players\n"+
		   "killed by said mobs. Thank you.  --ETB",
	      });
	smell = "The entry smells of Sandalwood Incense";
	::reset(arg);
	replace_program("room/room");
}