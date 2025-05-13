

  inherit "room/room";

  object goblin;
  object match;
  object torch;

  reset(arg) {
        
        if(arg) return;
        set_light(1);

  short_desc = "A dead end in the sewer system";

  long_desc = 
	"You have reached a dead end in the sewers. You can make out \n" +
	"a black gate in the wall. You also see a small sign located \n" +
	"on the wall beneath it. \n";

  dest_dir = ({
	"players/apollo/thieves/rooms/sewer04", "east",
             }); 

  items = ({
	"wall", "You see a slimy old wall with a sign on it and a metal gate in it",
	"sign", "There is something written on it",
	"air", "The air is full of an awful stench",
        "sewer", "You are walking through an old sewer",
	"gate", "You see a heavy black gate in the wall. You wonder \n" +
		"if you can open it",
	  });
	
	move_object((clone_object("players/apollo/thieves/monsters/goblin.c")),
		this_object());

  if (!present("torch",this_object())) {
	move_object(clone_object("/obj/torch"), this_object());
	move_object(clone_object("/players/apollo/thieves/objs/match"),
		this_object());
    }

  }

  init() {
	::init();
	add_action("open", "open");
	add_action("enter", "enter");
	add_action("fcn_read", "read");
	}

  open(str) {
	if (!str || str!="gate") {
		notify_fail("What do you want to open? \n");
 	    return 0;
	  }
	if (this_player()->query_guild()!=1) {
		write("You are not skilled enough to open this gate. \n");
	    return 1;	  
	  }
	if (str=="gate") {
		write("Arrggghhhh. \n");
		write("You successfully opened the heavy gate. \n");
                this_player()->move_player("west#/players/blade/guild/room");
	  }

  	return 1;
    }

  enter(str) {	
	if (!str || str!="gate") {
		notify_fail("What do you want to enter? \n");
	    return 0;
	  } 
	if (this_player()->query_guild()!=1) {
		write("You are not skilled enough to enter this gate. \n");
	    return 1;
	  }
	if (str=="gate") {
		write("Arrgghhhh. \n");
		write("You enter though the heavy gate. \n");
                this_player()->move_player("west#/players/blade/guild/room");
             return 1;
	  }
    }

  fcn_read(str) {
	if (!str || str!="sign") {
		notify_fail("What do you want to read? \n");
	    return 0;
	  }
	if (str=="sign") { 
		write("The Thief's Guild is beyond the gate. \n");
	    return 1;
	  }
    }




