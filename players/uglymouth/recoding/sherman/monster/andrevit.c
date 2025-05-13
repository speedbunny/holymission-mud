#include "../defs.h"

inherit GEN_VAMPIRE;

void reset( int arg ) {
  ::reset(arg);
  if( arg ) return;
  
  set_name( "andrevitch the vampire" );
  set_alias( "andrevitch" );
  set_short( "Andrevitch the vampire" );
  set_long( "Andrevitch the vampire.\n" );
  set_level( 50 );
  set_gender( 1 );
  set_al( -500 );
  set_ac( 30 );
  set_wc( 40 );
  set_chance( 20 );
  set_spell_mess1( "Andrevitch sinks his teeth into his opponent's "
    + "flesh.\n" );
  set_spell_mess2( "Andrevitch manages to sink his teeth deep into your "
    + "flesh and sucks a strength draining amount of blood from you.\n" );
  set_spell_dam( 100 );
  set_grave( ROOM_DIR + "grave06" );
}

varargs int attack( object theWeapon, int nrOfHand ) {
  if( ::attack( theWeapon, nrOfHand ) )
    ::attack( theWeapon, nrOfHand );
}

