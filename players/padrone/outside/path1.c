inherit "room/room";

void reset( int arg ) {
    if( !arg ) {
	set_light( 1 );
	short_desc = "A small path leading south";
	long_desc = "\
You are on a small path leading south through the bushes.\n\
A large castle raises before you to the south.\n\
\nThere is a sign here.\n";
	dest_dir = ({
	  "room/forest6", "north",
	  "/players/padrone/outside/path2", "south",
	});
	items = ({
	  "sign", "The sign reads: Danger Castle Construction Ahead!",
	});
    }
    ::reset( arg );
    replace_program( "room/room" );
}
