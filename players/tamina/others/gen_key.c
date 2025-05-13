/* 971031, Uglymouth: complete rewrite for use with /room/doorroom.c
 */
inherit "/obj/thing";

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;
  set_alias( "key" );
  set_value( 10 );
}

void set_key_data( string str ) {
  string type, code;

  if( sscanf( str, "%s %s", type, code ) != 2 ) {
    destruct( this_object() );
    return;
  }
  set_name( type + " key" );
  set_alt_name( code );
  set_short( "An " + type + " key" );
  set_long( "An " + type + " key. You wonder where it fits.\n" );
}
