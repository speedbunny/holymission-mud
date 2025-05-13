inherit "obj/treasure";

void reset( int arg ) {
    if( arg )
	return;
    set_id( "mox_jet" );
    set_name( "jet" );
    set_alias( "jet pendant" );
    set_short( "A jet pendant" );
    set_long( "\
This is a rough piece of jet suspended from an adamantite chain.\n\
You feel the gem pulsate under its own immense power.  This must\n\
be one of the legendary Moxes!\n" );
    set_weight( 0 );
    set_value( 2000 );
}
