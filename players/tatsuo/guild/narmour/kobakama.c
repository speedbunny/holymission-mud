inherit "/obj/armour";

reset( arg )
{
    ::reset( arg );

    if ( arg )
	return;

    set_name( "kobakama" );
    set_type( "leg" );
    set_ac(2);
    set_size(0);

    set_short( "a pair of kobakama" );
    set_long( "Kobakama are nihonese pants. They are made of leather.\n"+
              "Kobakama can be worn under the ninja-garb.\n" );
    set_value( 200 );
    set_weight( 1 );
}

query_ninja_wear( ) { return( 1 ); }
