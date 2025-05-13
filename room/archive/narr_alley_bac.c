#include "std.h"

#undef EXTRA_LONG
#define EXTRA_LONG\
    if (str == "well") {\
	write("You look down the well, but see only darkness.\n");\
	write("There are some iron handles on the inside.\n");\
	return;\
    }

#undef EXTRA_INIT
#define EXTRA_INIT add_action("go_down", "down");\
		add_action("south", "south");

FOUR_EXIT("room/vill_road1","north",
	 "room/post", "south",
	 "room/broker", "west",
         "players/airborne/temple/perfume", "east",
	 "Narrow alley",
         "A narrow alley. There is a well in the middle.\n"+
        "From the east drifts a variety of wonderful scents.\n"
       + "To the south is the 'post office', to the west the 'Brokers Assoc'.\n", 1)

go_down() {
    call_other(this_player(), "move_player", "down#room/well");
    return 1;
}

south() {
    if(this_player()->query_npc()) return 1;
    this_player()->move_player("south#room/post");
    return 1;
}

id(str) {
    if (str == "well")
	return 1;
}
