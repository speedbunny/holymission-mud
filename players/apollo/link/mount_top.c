

  inherit "room/room";

  reset(arg) {
        
        if(arg) return;
        set_light(1);

  short_desc = "";

  long_desc = 
	"You are on top of a mountain. There is a small plateau to the \n" +
	"east and you can see a higher plateau that looks like it goes \n" +
	"to the west. You can see a large grate on the ground. \n";

  dest_dir = ({
	"room/ravine", "down",
	"room/mount_top2", "east",
	"players/warlord/road1", "north",
	"players/kasgaroth/quest/shop", "south",
             }); 

  items = ({
	"grate", "You see a heavy black grate. You wonder if you can move it",
	  });

  }

  init() {
	::init();
	add_action("open", "open");
	add_action("move_up", "move");
	}

  open(str) {
	if (!str || str!="grate") {
		notify_fail("What do you want to open? \n");
 	    return 0;
	  }
	if (str=="grate") {
		write("Arrggghhhh. \n");
		write("You open the heavy grate. \n");
		this_player()->move_player("in#/players/apollo/link/aqua05");
	  }

  	return 1;
    }

  move_up(str) {
	if (!str || str!="grate") {
		notify_fail("What do you want to move? \n");
	    return 0;
	  } 
	if (str=="grate") {
		write("Arrgghhhh. \n");
		write("You move the heavy grate. \n");
		this_player()->move_player("in#/players/apollo/link/aqua05");
             return 1;
	  }

    }
