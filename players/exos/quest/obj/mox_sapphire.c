inherit "obj/treasure";

void reset( int arg ) {
    if( arg )
	return;
    set_id( "mox_sapphire" );
    set_name( "sapphire" );
    set_alias( "sapphire pendant" );
    set_short( "A sapphire pendant" );
    set_long( "\
This is a rather large sapphire suspended from a delicate silver chain.\n\
You feel the gem pulsate under its own immense power.  This must be one of\n\
the legendary Moxes!\n" );
    set_weight( 0 );
    set_value( 2000 );
}
