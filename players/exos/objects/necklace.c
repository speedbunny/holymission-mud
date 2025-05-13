inherit "obj/treasure";

string query_auto_load() {
    return ( "/players/exos/objects/necklace:" );
}

void reset( int arg ) {
    if( arg )
	return;
    set_id( "necklace" );
    set_name( "necklace" );
    set_short( "A sapphire necklace" );
    set_long( "\
This is a very delicate necklace made of hand twisted gold.\n\
A simple sapphire is set in a golden clasp.  A simple golden\n\
clasp holds the necklace together.\n" );
    set_weight( 0 );
    set_value( 0 );
}

int drop() {
    write( "You don't want to drop your necklace!\n" );
    return( 1 );
}
