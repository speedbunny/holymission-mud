inherit "/room/room";

#define NAME	"axlrose"
#define CNAME	capitalize(NAME)

int move(string str) {
    string err;
    int i;
    object ob;

    if(!str)
	str=query_verb();
    if(str!="down")
	return ::move(str);
    else if(find_call_out("move")!=-1) {
	write("The virtual area is being initialised... please wait.\n");
	return 1;
    }
    else
	ob=find_object("/players/axlrose/test_area/master");
    if(ob)
	return ::move(str);
    else {
	write("Initialising the virtual area system.\n\n");
	err=catch("/players/axlrose/test_area/master"->a_load_fun());
	if(err) {
	    printf("Failed to initialise the virtual area.\n\n%s\n",err);
	    return 1;
	}
	else {
	    write("Ok, you will be moved in shortly.\n");
	    call_out("move",2,str);
	    return 1;
	}
    }
}

// This procedure is called periodically to check for monsters
//    which need to be replaced or other values that need
//    to be reset.

void reset(int arg) {

    // Only initialise the room at load-time...
    if(!arg) {

	// First we need some light in here
	set_light(1);

	// Then lets set a short description in case we are in brief-mode
	short_desc=CNAME + "'s workroom",

	// Now the long standard room description
	//    change this to fit your style
	long_desc=
	"This is the workroom of "+CNAME+".\n" +
	"It looks empty ...\n";

	// We need some exits too ... lets set the destination directions
	dest_dir=({
	  "room/post", "post",
	  "room/church", "church",
	  "room/adv_guild", "guild",
	  "/players/axlrose/junk/room/field1", "field",
	  "/players/axlrose/test_area/entrance","down",
	});

	// Item descriptions can be placed in here
	items=({ 
	  "air","It's very thin up here",
	  "floor","The floor is dirty",
	});

	// Properties can be set like the following
	property = ({
	  "no_teleport","no_sneak","no_steal",
	});

#if 0
	//    The replace program will keep the room updated
	//    without further function calls
	replace_program("room/room");
#endif // 0

	// Close the initialisation block.
    }

    // Here you call the the reset in the inherited "room/room"
    ::reset(arg);
}

/********** You can place add_actions in here for special actions
init() {
    ::init();
    add_action("_blah","blah");
}
************/
