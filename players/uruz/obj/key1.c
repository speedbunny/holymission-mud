inherit "/obj/thing";

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;
  set_name( "black key" );
  set_alias( "key" );
  set_alt_name( "gambling_hall" );
  set_short( "A black key" );
  set_long( "A black key. You wonder where it fits...\n" );
  set_value( 10 );
}
