inherit "room/room";
#include "/players/nylakoorub/workroom/speak.h"



reset(arg) {
    if(!arg) {
    }
    set_light(1);
    short_desc = "Nylakoorub's Dimension";

    long_desc=
    "This is Nylakoorub's Dimension.\n"+
    "This place is where Nylakoorub spends most of his time on\n"+
    "Holy Mission.  Nylakoorub works very hard in this room.\n"+
    "It is a very High-Tech room, to the left is his computer\n"+
    "were he does all his coding from.  He keeps this room very clean\n"+
    "and organized (SO, DON'T TOUCH ANYTHING!!!).\n"+
    "\n";

    dest_dir=({
      "/players/ripken/workroom", "jim",
      "/players/nylakoorub/4th/crossroads", "4th",
      "/players/nylakoorub/clearing/path/rooms/c006", "clearing",
      "room/church", "church",
      "room/adv_guild", "guild", 
    });

    hidden_dir=({
    });
    items=({ 
      "computer","This is an very advanced computer system",
    });
    property = ({
      "no_teleport","no_sneak","no_steal",
    });
    smell = "It smells like a Nylakoorub lives here!";


    if(!speak) speak = "";
}

init()
{
    ::init();
    if(this_player()->query_real_name() != "nylakoorub"
      && !this_player()->query_archwiz() ) {
	add_action("speak", "say");
	add_action("request", "requestspeak");
	add_action("speak", "'", 1);
    } else {
	add_action("give_permission_to_speak", "grantspeak");
	add_action("remove_permission_to_speak", "removespeak");
	add_action("set_speak", "freespeak");

    }
    add_action("allowed_to_speak", "canspeak");
}
