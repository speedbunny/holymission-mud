inherit "obj/std_trans";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
    if(arg) return;
	set_short("The 7-islands frigate");
   	set_long(
	"A huge frigate has been assigned to patrol the 7-islands area and to explore for more islands.  "+
	"It boasts three large sails set on two masts.  A large crew scurries about setting the rigging and "+
	"preparing for the next leg of the voyage.  A gangplank connects the frigate to the shore.\n");
	set_inside_long(
	"A huge frigate has been assigned to patrol the 7-islands area and to explore for more islands.  "+
	"It boasts three large sails set on two masts.  A large crew scurries about setting the rigging and "+
	"preparing for the next leg of the voyage.  The captain is nowhere to be seen.\n");
	set_inside_enter("scurries across the gangplank.\n");
    set_outside_enter("climb aboard the frigate.\n");
  	set_outside_leave("climbs out of the frigate.\n");
	set_inside_leave("scurries off the frigate, jostling the gangplank as he goes.\n");
	set_water(1);
	stop_time(25);
	trans_time(20);
	set_rooms(7,({
		"/players/brainsprain/bis/rooms/pier2",                
		ir+"/creta2",
  		ir+"/ridge1",
 		ir+"/ecoast9",
		ir+"/rcoast6",
		ir+"/scoast4",
		ir+"/tcoast1",
	}));		
 	move_object(TO,"/players/brainsprain/bis/rooms/pier2"),
	::reset(arg);
}

