#include "../defs.h"

inherit GEN_VAMPIRE;

void reset( int arg ) {
  ::reset(arg);
  if( arg ) return;
  
  set_name( "nicolai the vampire" );
  set_alias( "nicolai" );
  set_short( "Nicolai the vampire" );
  set_long( "Nicolai the vampire.\n" );
  set_level( 40 );
  set_gender( 1 );
  set_al( -500 );
  set_ac( 18 );
  set_wc( 25 );
  set_chance( 20 );
  set_spell_mess1( "Nicolai's cold touch causes a look of panic in his "
    + "opponent's eyes.\n" );
  set_spell_mess2( "Nicolai's cold touch makes you panic for a "
    + "brief moment that seems to last for ever and ever.\n" );
  set_spell_dam( 40 );
  set_grave( ROOM_DIR + "grave04" );
  add_money( 501 + random( 500 ) );
}

// Multiple attacks: 1 in 2 chance on two attacks, 1 in 4 on three attacks.
varargs int attack( object theWeapon, int nrOfHand ) {
  if( ::attack( theWeapon, nrOfHand ) ) {
    if( random( 2 ) ) {
      ::attack( theWeapon, nrOfHand );
      if( random( 2 ) ) ::attack( theWeapon, nrOfHand );
    }
  }
}
