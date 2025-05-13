#include "../defs.h"

inherit GEN_VAMPIRE;

void reset( int arg ) {
  ::reset(arg);
  if( arg ) return;
  
  set_name( "marushka the vampire" );
  set_alias( "marushka" );
  set_short( "Marushka the vampire" );
  set_long( "Marushka the vampire.\n" );
  set_level( 40 );
  set_gender( 2 );
  set_al( -500 );
  set_ac( 22 );
  set_wc( 35 );
  set_grave( ROOM_DIR + "grave09" );
  add_money( 501 + random( 500 ) );
}
