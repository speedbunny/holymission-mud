#include "/players/blaarg/defs.h"
inherit "room/room";

reset(arg) {
    	set_light(1);


	short_desc="Anime entryway",

	long_desc=
	    "As you leave the portal you notice that you are in a street " +
	    "in Nihon...along the sides of the street you can see various " +
	    "shops selling all kinds of goods...far to the North you can " +
	    "see the Tendo All-For-Nothing Dojo.\n\n\n"+
	    "There is a RANMALAND sign here.\n";

	dest_dir=({
		"room/church", "portal",
		AROOMS+"road1", "north",
		 });

	items=({ 
	    "air","It is quite dusty on this street",
	    "road","The road is well-travelled",
	    "street","The road is well-travelled",
	    "sign","Welcome to RanmaLand!\n"+
		   "	We hope you enjoy your visit and maybe gain some "+
		   "experience as well as some fun memories! If you want "+
		   "to comment on the area, please mail me. "+
		   "Good Luck! "+
		   "-Evil Troll Blaarg\n",
	    "shops","The little shops run alongside the road, starting at the "+
		     "beginning of the village.\n"
	    "dojo","The dojo looks tiny from so far away",
	      });
	property = ({
		     "no_steal",
		    });
	smell = "This place is a bit dusty";

	::reset(arg);
    	replace_program("room/room");
}

