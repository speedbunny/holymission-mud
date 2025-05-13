inherit "room/room";
#include "/players/tuppence/include/defs.h"
void reset(int arg) {
    if(!arg){
	set_light(0);
	short_desc= "dead end";
	long_desc= "It seems you have come to a dead end in the hallway. Its pretty\n"+
	"plain here except for a big hole on the north wall. The hole looks\n"+
	"like it has been clawed out with HUGE claws. A terrible stench is\n"+
	"coming from the hole. You think you can enter it but you wonder\n"+
	"if you should?\n";
	items =
	({
	  "hole","A big clawed out hole on the north wall, maybe you can enter it",
	  "marks","BIG claw marks from some BIG monster",
	});
	dest_dir=
	({
	  FROOM+"dun6","south",
	});
    }
}

void init() {
    ::init();
    add_action("enter","enter");
}

int enter(string str) {
    if (!str || str != "hole") {
	notify_fail("Enter what?\n");
	return 1;
    }
    write("You have entered the hole.\n");
    TP->move_player("hole#"+FROOM+"tun1");
    return 1;
}
