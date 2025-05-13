inherit "obj/treasure";

void reset( int arg ) {
    if( arg )
	return;
    set_id( "mox_emerald" );
    set_name( "emerald" );
    set_alias( "emerald pendant" );
    set_short( "An emerald pendant" );
    set_long( "\
This is a rather large emerald suspended from a heavy golden chain.\n\
You feel the gem pulsate under its own immense power.  This must be\n\
one of the legendary Moxes!\n" );
    set_weight( 0 );
    set_value( 2000 );
}
