inherit "obj/armour";

void reset( int arg ) {
    ::reset( arg );
    if( arg )
	return;
    set_id( "crown_of_the_ages" );
    set_name( "crown" );
    set_type( "helmet" );
    set_ac( 0 );
    set_weight( 1 );
    set_value( 5000 );
    set_short( "Crown of the Ages" );
    set_long( "\
This is a rather heavy gold crown.  One of each of the power\n\
gems or 'Moxes' are arranged in a pentagram on the front.  This\n\
is the legendary Crown of the Ages, one of the most powerful\n\
sorcerous tools ever known.\n" );
}
