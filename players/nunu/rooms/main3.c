inherit "/room/room";

#include "/players/nunu/path.h"

reset(arg) {
	
	short_desc="short desc";

	long_desc="Generic long desc. "+
		  "nothing special. \n";

	set_light(1);

	items=({"something","There is something here.",
		"room","A room",
	      });

   /*property=({ "no_teleport","no_fight","no_steal","no_clean_up" }); */

	smell="You smell the brisk fresh air.\n";

	dest_dir=({"/room/church","north",
		   "/room/adv_guild","south",
		 });


	::reset(arg);
	
	replace_program("room/room");
}
