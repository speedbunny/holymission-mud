#include "std.h"

object f; 

init() {
    add_action("north", "north");
    add_action("south","south");
}

short() {
    return "Mountain path";
}

long() {
    write("Limestone plateaus form a rather flat looking countryside of hills.\n"+
  "There are exits to the north and to the south\n");
}

south() {
 call_other(this_player(), "move_player", "south#players/rasta/room/path31");
 return 1;
}

north()
{
 call_other(this_player(), "move_player", "south#players/rasta/room/path51");
  return 1;
}

reset(arg) {
    if (!arg)
	set_light(1);
  if(!f) {
f = clone_object("players/rasta/obj/fighter2");
move_object(f,this_object());
    }
}

