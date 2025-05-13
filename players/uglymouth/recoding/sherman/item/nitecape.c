inherit "/obj/armour";

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;

  set_name( "black cape" );
  set_alias( "cape" );
  set_alt_name( "night cape" );
  set_short( "A jet black cape" );
  set_long( "This jet black cape is spun from the thin and delicate "
    + "material, soft and velvety, that is the extract of night itself.\n" );
  set_type( "cloak" );
  set_ac( 0 );
  set_weight( 0 );
  set_light( -1 );
  set_value( 500 );
}
