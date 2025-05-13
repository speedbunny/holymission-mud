inherit "/obj/armour";

reset( arg )
{
    ::reset( arg );

    if ( arg )
	return;

    set_name( "kusari-kabuto" );
    set_type( "helmet" );
    set_ac(1);
    set_size(0);

    set_short( "kusari-kabuto" );
    set_long( "This is the typical hood of a ninja. It is made of cloth\n"+
              "and padded with leather to soften blows at the head.\n" );
    set_value( 300 );
    set_weight(1);
}

query_ninja_wear( ) { return( 1 ); }
