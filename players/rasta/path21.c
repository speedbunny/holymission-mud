#include "std.h"

object fighter;

init() {
    add_action("north", "north");
    add_action("south","south");
}

short() {
    return "Mountain path";
}

long() {
    write("Again you feel natural mystics flowing through the air.\n"+
  "There are exits to the north and to the south.\n");
}

south() {
 call_other(this_player(), "move_player", "south#players/rasta/room/path11");
 return 1;
}

north()
{
 call_other(this_player(), "move_player", "south#players/rasta/room/path31");
 return 1;
}

reset(arg) {
    if (!arg)
	set_light(1);
    if (!fighter) {
	fighter = clone_object("players/rasta/obj/fighter");
	move_object(fighter, this_object());
    }
}

