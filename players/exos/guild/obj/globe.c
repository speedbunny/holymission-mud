inherit "/obj/thing";
int light_level;
void set_llevel( int arg );

void reset( int arg ) {
    ::reset( arg );
    if( arg )
	return;
    set_name( "globe" );
    set_short( "A Globe of Light" );
    set_long( "A globe emitting warm, dim light.\n" );
    set_weight( 0 );
    set_llevel( 1 );   
}

drop() {
    write( "As you drop your ball of light it disappears.\n" );
    destruct( this_object() );
    return( 1 );
}

void set_llevel( int arg ) { light_level = arg; }
void set_time( int time ) { call_out( "end_light", time ); }

int light( int arg ) {
    if( arg )
	return( set_light( light_level ) );
    return( set_light( -light_level ) );
}

status end_light() {
    write( "Your globe of light disappears.\n" );
    say( environment()->query_name() + "'s globe of light disappears.\n" );
    if( light( 0 ) <= 0 )
	tell_room( environment( environment() ), "It turns dark.\n" );
    destruct( this_object() );
    return( 1 );
}
