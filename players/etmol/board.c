inherit "/obj/board";

void reset( int arg ) {
  ::reset( arg );
  if ( arg ) return;

 set_file( "/players/etmol/board" );
  set_name( "Etmol's board" );
  set_short( "Etmol's board\n");
}
