

  inherit "room/room";

  reset(arg) {
        
        if(arg) return;
        set_light(1);

  short_desc = "An Aquaduct";

  long_desc = 
	"You have come to one of the many dead ends in the immense sewer \n" +
	"system tunneling deep under the main streets and paths of Holy \n" +
	"Mission. As you look around you see many decomposed skeletons of \n" +
	"animals and people that did not make it out of the sewers alive. \n" +
	"You can even make out small rats scurrying around feasting on \n" +
	"whatever fallen prey they can find. At the end of the tunnel \n" +
	"you see a small grate in the ceiling. Leading up you see a small \n" +
	"ladder. \n";

  dest_dir = ({
	"players/apollo/link/sewer36", "south",
             }); 

  items = ({
	"air", "The air is full of an awful stench",
	"skeletons", "You see a slightly decomposed body of an animal",
        "sewer", "You are walking through an old sewer",
	"ladder", "You see a small step ladder leading up towards a grate",
	"grate", "You see a heavy black grate in the ceiling. You wonder \n" +
		"if you can move it",
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
		this_player()->move_player("up#/players/apollo/link/aqua02");
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
		this_player()->move_player("up#/players/apollo/link/aqua02");
             return 1;
	  }

    }

  climb(str) {
	if (str=="ladder") {
		write("You climb up the small ladder. \n");
		write("You hit your head and fall back down. \n");
		write("Ouch...... \n");
//		this_player()->move_player("down ladder#/players/apollo/link/aqua01");
		this_player()->hit_player(10+random(10));
	  }

	else { write("What do you want to climb? \n"); }

	return 1;
    }


