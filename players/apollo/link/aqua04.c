

  inherit "room/room";

  reset(arg) {
        
        if(arg) return;
        set_light(1);

  short_desc = "An Aquaduct";

  long_desc = 
	"You are climbing up an old aquaduct. It is no longer in use \n" +
	"anymore, because only a small trickle of water can be seen running \n" +
	"slowly down the middle of the channel. Leading up you see a small \n" +
	"ladder. \n";

  dest_dir = ({
	"players/apollo/link/aqua03", "down",
             }); 

  items = ({
	"water", "A small trickle of water is slowly running downwards",
	"ladder", "You see a small step ladder continuing up the aquaduct",
	  });

  }

  init() {
	::init();
	add_action("climb", "climb");
	}

  climb(str) {
	if (!str || str!="ladder") {
		notify_fail("What do you want to climb? \n");
	    return 0;
	  }
	if (str=="ladder") {
		write("You climb up the small ladder. \n");
		this_player()->move_player("up#/players/apollo/link/aqua05");
	  }

	return 1;
    }


