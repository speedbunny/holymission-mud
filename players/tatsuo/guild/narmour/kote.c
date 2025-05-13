inherit "/obj/armour";

reset( arg )
{
    ::reset( arg );

    if ( arg )
	return;

    set_name( "kote" );
    set_alias( "a pair of kote" );
    set_type( "arm" );
    set_ac(2);
    set_size(0);

    set_short( "a pair of kote" );
    
    set_long( 
       "Kote are chain arm-sleeves. They can be worn under ninja-garb.\n" );
    set_value( 400 );
    set_weight(1);
}

query_ninja_wear( ) { return( 1 ); }
