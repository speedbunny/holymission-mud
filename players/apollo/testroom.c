inherit "room/room";

reset(arg) {

    if(arg) return;

    set_light(1);

    short_desc = "Apollo's test room";

    long_desc = "Apollo's test room. Here monsters are tested so that\n" +
                "they cannot wimpy away.\n";

    dest_dir = ({
//        "/players/apollo/testroom1", "north",       
    });


    property=({"no_teleport","no_sneak"});

	move_object(clone_object("/players/apollo/private/dummy"),
	   this_object());

}

init() {

    ::init();
}


