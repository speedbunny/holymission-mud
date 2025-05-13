/* rope_ladder.c */
/* Recode - Exos 961028 */

inherit "/room/room";
#include "walker.h"

void reset(int flag) {
if(!flag) {
	set_light(1);
        short_desc = "On a rope ladder";
        dest_dir = ({
"players/padrone/walker/ladder_room", "up",
});
     }
::reset(flag);
}


init() {
    ::init();
    add_action("fcn_down", "down");
}

fcn_down() {

    if (call_other(CASTLE, "query_airborne")) {
	write("The castle is flying high up among the clouds.\n");
	write("You cannot reach the ground.\n");
	return 1;
    }

    this_player()->move_player("down", call_other(CASTLE, "query_environment"));
    return 1;
} /* down */

long(str) { 
    if (set_light(0) == 0){ 
	write("It is dark.\n"); 
	return; 
    }  
    write("You are hanging on a rope ladder between the giant legs of the\n" +
	  "walking castle. Above you a small opening leads into the castle,\n");
    if (call_other(CASTLE, "query_airborne"))
	write("and very, very far below you, you can see the ground.\n");
    else
	write("and below you, you can see " +
	      call_other(CASTLE, "query_environment")->short() + ".\n");
    write("There are two obvious exits, up and down.\n");
} /* long */
