/* secret_police/hall.c */

inherit "/room/room";   // whisky 
#include "../../../obj/door.h"

object obj_1, obj_2;	/* Used by the MAKE_DOORS macro */


reset(arg) {

    if(!arg) {
       set_light(1);
       dest_dir =
       ({
          "players/padrone/secret_police/office", "north",
	  "players/padrone/secret_police/backroom", "south",
	  "players/padrone/secret_police/sleeping_room", "east",
	  "players/padrone/secret_police/interrogation_room", "west",
       });
       short_desc = "A small hall behind the shop";
       long_desc =
	  "You are in a small hall behind the shop.\n" +
	  "There are doors in all directions, and on the wall there is a poster\n" +
	  "with the text: \"The Secret Police - for the Safety of the Realm!\".\n";

	MAKE_DOORS("players/padrone/secret_police/hall", "west", "players/padrone/secret_police/interrogation_room", "east", "iron", "interrogation", "There is a sign saying \"KEEP OUT!\" on this door.\n", 1, 1, 1)
    }
    else {
       if (!obj_1)
            obj_1 = present("door",this_object());
       if (obj_1)
       {
	obj_1->set_closed(1);
	obj_1->set_locked(1);
	obj_1->set_both_status();
       }
    }
} 
