
/* secret_police/hall.c */
// Kasgaroth: better long, strict_types

inherit "room/room";   // whisky 
#include "/obj/door.h"

object obj_1, obj_2;    /* Used by the MAKE_DOORS macro */

void reset(int arg)
{
    if(!arg) 
    {
	set_light(1);
	short_desc = "Short Hall";
	long_desc =
	"You stand in a small hall behind the shop.  "
	+ "Doors stand at the cardinal directions, and a plaque on the "
	+ "wall reads:\n"
	+ "'The Service shall stand now and forever to protect and serve.'\n";
	dest_dir =
	({
	  "players/padrone/secret_police/office", "north",
	  "players/padrone/secret_police/backroom", "south",
	  "players/padrone/secret_police/sleeping_room", "east",
	  "players/padrone/secret_police/interrogation_room", "west",
	});
	property = ({ "no_clean_up" });

	MAKE_DOORS("players/padrone/secret_police/hall", "west", 
	  "players/padrone/secret_police/interrogation_room", "east",
	  "iron", "interrogation", "There is a sign saying \"KEEP OUT!\" on this door.\n", 1, 1, 1)

	if (!obj_1)
	    obj_1 = present("door",this_object());
	else if(obj_1)
	{
	    obj_1->set_closed(1);
	    obj_1->set_locked(1);
	    obj_1->set_both_status();
	} 
    }
}

