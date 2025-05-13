#include "../defs.h"

inherit GEN_VAMPIRE;

void reset( int arg ) {
  ::reset(arg);
  if( arg ) return;
  
  set_name( "boris the bloodthirsty vampire" );
  set_alias( "boris" );
  set_short( "Boris the bloodthirsty vampire" );
  set_long( "Boris the bloodthirsty vampire.\n" );
  set_level( 50 );
  set_race( "undead" );
  set_gender( 1 );
  set_al( -500 );
  set_ac( 30 );
  set_wc( 40 );
  set_chance( 20 );
  set_spell_mess1( "Boris sinks his teeth into his opponent's flesh.\n" );
  set_spell_mess2( "Boris manages to sink his teeth deep into your "
    + "flesh and sucks a strength draining amount of blood from you.\n" );
  set_spell_dam( 100 );
  set_grave( ROOM_DIR + "grave02" );
}

varargs int attack( object theWeapon, int nrOfHand ) {
  if( ::attack( theWeapon, nrOfHand ) )
    ::attack( theWeapon, nrOfHand );
}

