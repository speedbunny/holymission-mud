/* gate_control.c */
/* Recode - Exos 961026 */

inherit "/room/room";
#include "walker.h"

id (str) {
    return !str || str == "switch" || str == "machine" || str == "big machine";
}

long(str) {
    if (set_light(0) == 0){ 
	write("It is dark.\n"); 
	return; 
    }  
    if (str == "switch") {
	write("This is a small switch that can be moved up and down.\n");
	if (call_other(CASTLE, "query_drawbridge_down"))
	    write("It is currently in position 'down'.\n");
	else
	    write("It is currently in position 'up'.\n");
	return;
    }
    if (str == "machine" || str == "big machine") {
	write("A big machine that occupies this small room.\n");
	return;
    }
    write("This is a small room occupied by a big machine.\n" +
      "From this room, the drawbridge can be lowered and raised.\n" +
      "The only obvious exit is east.\n" +
      "There is a small switch here.\n");
}

void reset(int arg) {
    if(!arg) {
	set_light(1);
	short_desc="The Gate Control Room of the Walking Castle";
	dest_dir = ({
	  "/players/padrone/walker/gate_room","east",
	});
	clone_list=({
	  1, 1, "pirate", "/players/padrone/monsters/big_smelly_pirate", 0,
	  -1, 1, "cutlass", "/players/padrone/obj/cutlass", 0,
	  -1, 1, "jacket", "/players/padrone/obj/jacket", 0,
	  -1, 1, "helmet", "/players/padrone/obj/helmet", 0,
	});
    }
    ::reset(arg);
} /* reset */

init() 
{
    ::init();
    add_action("fcn_move", "move");
    add_action("flip", "flip");
    add_action("do_switch", "switch");
} /* init */

fcn_move(str) {
    string what, where, player_name;
    int n;
    object pirate;

    if(!str) return 0;
    pirate=present("pirate", this_object());

    if (str == "switch") {
	write("Yes, but in what direction?\n");
	return 1;
    }

    n = sscanf(str, "%s %s", what, where);
    player_name = this_player()->query_name();

    if (n == 2 && (what == "switch")) {
	if (pirate && living(pirate) && present(pirate, this_object()))  {
	    write("You try to move the switch, but the pirate stands in the way.\n");
	    say(player_name +
	      " tried to move the controls, but the pirate stands in the way.\n");
	    return 1;
	}
	if (what == "switch") {
	    if (where == "up" || where == "u") {
		say(player_name + " moved the small switch up.\n");
		write("You move the small switch up.\n");
		call_other(CASTLE, "set_drawbridge_down", 0);
	    }
	    else if (where == "down" || where == "d") {
		say(player_name + " moved the small switch down.\n");
		write("You move the small switch down.\n");
		call_other(CASTLE, "set_drawbridge_down", 1);
	    }
	    else
		write("What a strange direction.\n");
	    return 1;
	}
    }
    else
	return 0;
} /* move */

flip(str) {
    if (str != "switch")
	return 0;
    if (call_other(CASTLE, "query_drawbridge_down"))
	return move("switch up");
    else
	return move("switch down");
} /* flip */

do_switch(str) {
    return move("switch " + str);
} /* do_switch */
