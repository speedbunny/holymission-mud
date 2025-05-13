

  inherit "room/room";

  reset(arg) {
        
        if(arg) return;
        set_light(1);

  short_desc = "An Aquaduct";

  long_desc = 
	"You are climbing up an old aquaduct. It is no longer in use \n" +
	"anymore, because only a small trickle of water can be seen running \n" +
	"slowly down the middle of the channel. You see a small grate ahead \n" +
	"of you. \n";

  dest_dir = ({
	"players/apollo/link/aqua04", "down",
             }); 

  items = ({
	"ladder", "You see a small step ladder leading towards the grate",
	"grate", "You see a heavy black grate. You wonder if you can move it",
	  });

  }

  init() {
	::init();
	add_action("open", "open");
	add_action("move_up", "move");
	add_action("climb", "climb");
	}

  open(str) {
	if (!str || str!="grate") {
		notify_fail("What do you want to open? \n");
 	    return 0;
	  }
	if (str=="grate") {
		write("Arrggghhhh. \n");
		write("You open the heavy grate. \n");
		this_player()->move_player("out#/room/mount_top");
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
		this_player()->move_player("out#/room/mount_top");
             return 1;
	  }

    }

  climb(str) {
	if (str=="ladder") {
		write("You climb up the small ladder. \n");
		write("You hit your head and fall back down. \n");
		write("Ouch...... \n");
		this_player()->move_player("down ladder#/players/apollo/link/aqua01");
		this_player()->hit_player(10+random(20));
	  }

	else { write("What do you want to climb? \n"); }

	return 1;
    }


