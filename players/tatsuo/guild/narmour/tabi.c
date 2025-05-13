inherit "/obj/armour";

reset( arg )
{
    ::reset( arg );

    if ( arg )
	return;

    set_name( "tabi" );
    set_type( "boots" );
    set_ac(2);
    set_size(0);

    set_short( "a pair of tabi" );
    set_long( "Tabi are the typical nihonese split-toed boots.\n" );
    set_value( 50 );
    set_weight(1);
}

query_ninja_wear( ) { return( 1 ); }
