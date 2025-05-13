inherit "room/room";

void reset( int arg ) {
    if( !arg ) {
	set_light( 1 );
	short_desc = "Harper Safe House";
	long_desc = "Harper Safe House #2\n";
	smell = "This place smells like a Safe House.";
	dest_dir = ({
	  "room/crop5", "out",
	});
	items = ({
	  "room", "A Harper Safe House",
	});
	clone_list = ({
	});
    }
    ::reset( arg );
}

void init( ) {
    ::init( );
}
