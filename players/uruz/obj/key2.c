inherit "/obj/thing";

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;
  set_name( "iron key" );
  set_alias( "key" );
  set_alt_name( "gatekey" );
  set_short( "An iron key" );
  set_long( "This is an iron key matching the lock of a gate.\n" );
  set_value( 10 );
}
