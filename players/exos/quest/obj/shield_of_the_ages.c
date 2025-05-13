inherit "obj/armour";

void reset( int arg ) {
    ::reset( arg );
    if( arg )
	return;
    set_id( "shield_of_the_ages" );
    set_name( "shield" );
    set_type( "shield" );
    set_ac( 2 );
    set_weight( 3 );
    set_value( 10000 );
    set_short( "Shield of the Ages" );
    set_long( "\
The legendary Shield of the Ages!  It is made of Titanium Steel\n\
with the mystic pentagram engraved in the middle.  This shield\n\
is rumored to turn most blows effortlessly!\n" );
}
