#include "std.h"

object f;

init() {
    add_action("west", "west");
    add_action("south","south");
    add_action("north","north");
}

short() {
    return "Mountain top";
}

long() {
    write("This is a peaceful, unsuspected place high up over Rasta City\n" +
 "It is cold and you are freezing.\n"+
  " There are exits to the west, north and to the south\n");
}

south() {
 call_other(this_player(), "move_player", "south#players/rasta/room/path6");
 return 1;
}
north() {
 call_other(this_player(), "move_player", "north#players/rasta/room/path11");
}
west()
{
 write("You come in from the bright light and green mountains to the deep,\n"+
 "dark caverns of stone and ice.\n");
 call_other(this_player(), "move_player", "south#players/rasta/room/ice");
  return 1;
}

reset(arg) {
    if (!arg)
	set_light(1);
}

