

  inherit "room/room";
  object big_rat;

  reset(arg) {
        
        if(arg) return;
        set_light(1);

  short_desc = "A dead end in the sewer system";

  long_desc = 
	"You have reached a dead end in the sewers. You can make out \n" +
	"a black grate in the ceiling. You also see a small sign located \n" +
	"on the wall beneath it. \n";

  dest_dir = ({
	"players/apollo/thieves/rooms/sewer18", "south",
             }); 

  items = ({
	"wall", "You see a slimy old wall with a sign on it",
	"sign", "There is something written on it",
	"air", "The air is full of an awful stench",
        "sewer", "You are walking through an old sewer",
	"grate", "You see a heavy black grate in the ceiling. You wonder \n" +
		"if you can move it",
	  });

	move_object((clone_object("players/apollo/thieves/monsters/big_rat.c")),
		this_object());

  }

  init() {
	::init();
	add_action("open", "open");
	add_action("move_up", "move");
	add_action("fcn_read", "read");
	}

  open(str) {
	if (!str || str!="grate") {
		notify_fail("What do you want to open? \n");
 	    return 0;
	  }
	if (str=="grate") {
		write("Arrggghhhh. \n");
		write("You open the heavy grate. \n");
		this_player()->move_player("up#/room/main_shop");
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
		this_player()->move_player("up#/room/main_shop");
             return 1;
	  }

    }

  fcn_read(str) {
	if (!str || str!="sign") {
		notify_fail("What do you want to read? \n");
	    return 0;
	  }
	if (str=="sign") {
		write("The Town Shop is up. \n");
	    return 1;
	  }
    }




