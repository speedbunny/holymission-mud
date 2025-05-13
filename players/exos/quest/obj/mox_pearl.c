inherit "obj/treasure";

void reset( int arg ) {
    if( arg )
	return;
    set_id( "mox_pearl" );
    set_name( "pearl" );
    set_alias( "pearl pendant" );
    set_short( "A pearl pendant" );
    set_long( "\
This is a rather large pearl suspended from a mithril chain.\n\
You feel the gem pulsate under its own immense power.  This\n\
must be one of the legendary Moxes!\n" );
    set_weight( 0 );
    set_value( 2000 );
}
