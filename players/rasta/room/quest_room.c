// Mangla: commented out the italras clone since the file doe snot exist.
#include "std.h"

object italras;

init() {
    add_action("west", "west");
}

short() {
    return "ital place";
}

long() {
    write("This is an ital garden where Rastas used to cultivate\n" +
"their sensimilia ganja. Unfortunately the blazing sun destroyed\n" +
"the Rastamen's harvest and they don't have any seed to grow more\n" +
  "kaya.\n There is an exit to the west. \n");
}

west() {
 call_other(this_player(), "move_player", "west#players/rasta/room/maze1");
 return 1;
}

reset(arg) {
    if (!arg)
	set_light(1);
/*
    if (!italras) {
	italras = clone_object("players/rasta/obj/italras");
	move_object(italras, this_object());
    }
*/
}

query_property(str) { return str=="no_teleport"; }
