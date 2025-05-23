inherit "/room/room";

void reset( int flag ) {
    if( !flag ) {
	set_light(1);
	dest_dir = ({
	  "players/padrone/outside/front_yard", "west",
	  "players/padrone/outside/e", "south",
	});
	short_desc = "Northeast of Padrone's Castle";
	long_desc = "\
This is a small path that goes all the way around Padrone's Castle.\n\
You are at the northeast corner of the castle, and the path leads south\n\
beneath the eastern wall of the castle.  To the west, you can enter the\n\
front yard of the castle, and from there you can go south through the\n\
main gates into the castle itself.\n\
To the north and to the east you see nothing but the\n\
dark and twisted trees of the impenetrable forest.\n";
    }
    ::reset( flag );
    replace_program( "room/room" );
}
