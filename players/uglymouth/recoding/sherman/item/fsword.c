inherit "obj/weapon";

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;
  set_name( "flaming sword" );
  set_alias( "sword" );
  set_short( "A flaming sword" );
  set_long( "A mighty sword, prefered by demons.\n" );
  set_class( 30 );
  set_weight( 3 );
  set_value( 5000 );
  set_hit_func( this_object() );
}

int weapon_hit( object ob ) {
  if( random( 100 ) < 50 ) {
    printf( "The sword burns your oponent.\n" );
    tell_object( ob,
      "The flaming sword engulfs you with incredible heat!! ARGHH \n" );
    return 100;
  }
  return 0;
}

int drop() {
  printf( "The flaming sword disappears as it is separated from "
    + "the lich Balor.\n" );
  say( "The flaming sword disappears as it is separated from "
    + "the lich Balor.\n" );
  destruct( this_object() );
  return 1;
}

int weapon_class() {
  if( environment() && environment()->id( "lich" ) ) return 100;
  return ::weapon_class();
}

