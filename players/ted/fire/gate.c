#include "/players/ted/defs.h"

inherit "room/room";

int is_open;

reset(arg) {
    is_open = 0;
    ::reset(arg);
    if(!arg) {
	set_light(1);
	short_desc = "Large Red Castle";
	long_desc =
	"The walls of this grim fortress are made of red stone, the\n"+
	"color of dried blood. A large iron gate blocks the entrance\n"+
	"to the castle. You can hear rumbling voices and the tramp of\n"+
	"booted feet from inside.\n"+
	"****Be sure to look at everything in this castle****\n";
	dest_dir = ({
	  HOT + "fire_giant","south"
	});
	items = ({
	  "castle","This is the dreaded stronghold of the evil fire giants"+
	  "Only the very brave or the very foolish would dare to"+
	  "enter without a giantslayer"
	});
    }
}


init() {
    ::init();
    add_action("do_open","open");
    add_action("go_north","north");
}

long(str) {
    ::long(str);
    if(str == "gate" || str == "iron gate") {
	write("This is a massive iron gate. It appears to be made of\n");
	write("a red iron ore, baddly rusted. It looks as if a strong\n");
	write("person could open it.\n");
	if(is_open) write("The gate is already open.\n");
    }
}

do_open(str) {
    if(this_player()->query_str() > 14) {
	is_open = 1;
	write("You open the gate.\n");
	write("It is now possible to go north into the castle.\n");
	return 1;
    }
    write("You are not strong enough to open the gate.\n");
    return 1;
}

go_north() {
    if(is_open) {
	call_other(this_player(),"move_player","north#players/ted/fire/guard");
	return 1;
    } else {
	write("The gate is closed.\n");
	say(capitalize(this_player()->query_name())+" walks into the closed gate.\n");
	say(capitalize(this_player()->query_name())+" feels very foolish.\n");
	return 1;
    }
}

id(str) {
    if(::id(str)) return 1;
    return(str == "gate" || str == "iron gate" || str == "castle");
}
