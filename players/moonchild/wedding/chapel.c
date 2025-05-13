#include "room.h"

object preacher;

#undef EXTRA_RESET
#define EXTRA_RESET\
  extra_reset();

extra_reset() {
    move_object(preacher="players/moonchild/wedding/preacher",this_object());
    property = ({ "no_fight" });
}

ONE_EXIT("room/church", "south",
  "Wedding chapel",
  "You are standing in a beautiful chapel. Light streams in through the delicate\n"
  + "stained glass windows, flooding the chapel in brightness and colour. Above you\n"
  + "you can see the chapel organ, with its intricately embossed piping. There are\n"
  + "lots of seats here, where people sit for services and wedding ceremonies.\n", 1)

init() {
    ::init();
    add_action("sit", "sit");
}

try_attack(ob) { return "room/church"->try_attack(ob); }

sit() {
    write("You sit down.\n");
    say(this_player()->query_name() + " sits down.\n");
    return 1;
}

id(str) { return str=="windows" || str=="organ" || str=="seats"; }

long(str) {
    if(str=="windows") {
	write("The stained glass windows are beautiful.\n");
	return 1;
    }
    if(str=="organ") {
	write("A huge majestic organ, played only during church ceremonies.\n");
	return 1;
    }
    if(str=="seats") {
	write("Seats for sitting in.\n");
	return 1;
    }
    ::long();
}
