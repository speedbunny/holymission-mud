inherit "obj/treasure";

void reset( int arg ) {
    if( arg )
	return;
    set_id( "mox_ruby" );
    set_name( "ruby" );
    set_alias( "ruby pendant" );
    set_short( "A ruby pendant" );
    set_long( "\
This is a rather large ruby suspended from a thick copper chain.\n\
You feel the gem pulsate under its own immense power.  This must\n\
be one of the legendary Moxes!\n" );
    set_weight( 0 );
    set_value( 2000 );
}
