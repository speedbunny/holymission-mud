#include "../defs.h"

inherit GEN_VAMPIRE;

void reset( int arg ) {
  ::reset(arg);
  if( arg ) return;
  
  set_name( "yurei the vampire" );
  set_alias( "yurei" )
  set_short( "Yurei the vampire" );
  set_long( "Yurei the vampire.\n" );
  set_level( 40 );
  set_gender( 1 );
  set_al( -500 );
  set_ac( 22 );
  set_wc( 35 );
  set_grave( ROOM_DIR + "grave03" );
  add_money( 501 + random( 500 ) );
}
