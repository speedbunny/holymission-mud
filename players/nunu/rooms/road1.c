inherit "/room/room";

#include "/players/nunu/path.h"

reset(arg) {
	
	short_desc="short desc";

        long_desc="As you are walking down the path, you notice the walkway "+
                  "change into a beautiful coblestone road. Above you is a "+
                  "sign that lays centered between two posts. On both sides "+
                  "of the road there is a meadow of rich green grass which "+
                  "seems to continue as far as you can see.\n";

	set_light(1);

	items=({"something","There is something here.",
		"room","A room",
	      });

   /*property=({ "no_teleport","no_fight","no_steal","no_clean_up" }); */

	smell="You smell the brisk fresh air.\n";

	dest_dir=({"/room/church","north",
		   ROOM+"road2.c","south",
		 });


	::reset(arg);
	
	replace_program("room/room");
}
