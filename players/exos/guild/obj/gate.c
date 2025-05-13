inherit "obj/thing";
object source, place;
int dest();

void reset( int arg ) {
    ::reset( arg );
    if( arg )
	return;
    set_name( "gate" );
    set_alias( "crack" );
    set_short( "A crack in the fabric of space" );
}

void init() {
    ::init();
    add_action( "enter", "enter" );
}

int enter( string arg ) {
    if( !source )
	dest();
    if( id( arg ) ) {
	printf( "As you enter the gate, the world vanishes.\n\
Some moments later you arrive next to %s!\n", source->query_name() );
	this_player()->move_player( "into the gate", place );
	return( dest() );
    }
}

int get() { return( 0 ); }

void long() {
    printf( "The crack seems to be a gate to %s.\n", source->query_name() );
}

void set_gate( object target ) {
    if( !target || !target->query_player() ) 
	destruct( this_object() );
    tell_room( environment(), "A crack apears in the fabric of space.\n" );
    source=target;
    place=environment( target );
    call_out( "chk_place", 1 );
    call_out( "dest", 60 );
}

void chk_place() {
    if( !source || place != environment( source ) )
	dest();
    call_out( "chk_place", 1 );
}

int dest() {
    tell_room( environment( this_object() ), short() + " vanishes.\n" );
    if( find_call_out( "chk_place" ) )
	remove_call_out( "chk_place" );
    if( find_call_out( "dest" ) )
	remove_call_out( "dest" );
    destruct( this_object() );
    return( 1 );
}
