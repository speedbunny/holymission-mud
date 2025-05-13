inherit "obj/monster.c";

int busy_catching;

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;
  set_name( "ear" );
  set_short( "Uglymouth's echoing ear" );
  set_long( "This is Uglymouth's echoing ear.\n" );
  set_level( 1 );
  busy_catching = 0;
}

void catch_tell( string str ) {
  if( busy_catching ) return;
  if( !find_player( "uglymouth" ) ) return;
  busy_catching = 1;
  tell_object( find_player( "uglymouth" ),
    sprintf( "[*EAR %s*] %s\n", explode( file_name( this_object() ), "#" )[1],
    str ) );
  busy_catching = 0;
}
