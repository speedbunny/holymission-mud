inherit "/obj/armour";

reset( arg )
{
    ::reset( arg );

    if ( arg )
	return;

    set_name( "tekagi" );
    set_alias( "pair of tekagi" );
    set_type( "glove" );
    set_ac(1);
    set_size(0);

    set_short( "a pair of tekagi" );
    set_long( "This is a pair of tekagi. Tekagi are gloves with spikes on them.\n" +
      "They are used by ninjas.\n" );
    set_value( 100 );
    set_weight(1);
}

query_ninja_wear( ) { return( 1 ); }
