inherit "obj/treasure";

void reset( int arg ) {
    if( arg )
	return;
    set_id( "lotus" );
    set_name( "lotus" );
    set_alias( "black lotus" );
    set_short( "A black lotus blossum" );
    set_long( "\
This is a very delicate black flower.  One of the rarest blossums in the\n\
world.  They are rumored to have many magical uses.  You are certain\n\
this flower will attract a LOT of interest in the markets and shops.\n" );
    set_weight( 0 );
    set_value( 10000 );
}

void init() {
    ::init();
    add_action( "_eat", "eat" );
}

status _eat( string str ) {
    if( !str ) 
	return ( 0 );
    if( str != "lotus" && str != "black lotus" )
	return ( 0 );
    write( "You eat the delicate flower.\n" );
    this_player() -> restore_spell_points( this_player() -> query_max_sp() );
    destruct( this_object() );
    return ( 1 );
}
