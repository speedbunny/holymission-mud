#include "../defs.h"

inherit GEN_VAMPIRE;

void reset( int arg ) {
  ::reset(arg);
  if( arg ) return;
  
  set_name( "natanya the child vampire" );
  set_alias( "natanya" );
  set_short( "Natanya the child vampire" );
  set_long( "Natanya the child vampire. Don't mistake her size for "
    + "weakness though.\n" );
  set_level( 35 );
  set_gender( 2 );
  set_al( -500 );
  set_ac( 18 );
  set_wc( 30 );
  set_chance( 20 );
  set_spell_mess1( "Natanya stares into her opponent's eyes.\n" );
  set_spell_mess2( "Natanya's stare drains you with a freezing flash "
    + "along your spine.\n" );
  set_spell_dam( 60 );
  set_grave( ROOM_DIR + "grave01" );
}
