#include "../defs.h"

inherit "obj/monster";

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;
  set_name( "shade" );
  set_short( "A shade" );
  set_long( "This uncorporeal undead known as a shade. It is hardly visible "
    + "even in these dark caves and it would be anywhere except in broad "
    + "daylight on an open plain. It's ethereal touch drains your strength "
    + "real enough though.\n" );
  set_level( 20 );
  set_race( "undead" );
  set_al( -150 );
  set_ac( 12 );
  set_wc( 30 );
  set_aggressive( 1 );
  add_money( 401 + random( 400 ) );
}

varargs int attack( object theWeapon, int nrOfHand ) {
  if( ::attack( theWeapon, nrOfHand ) )
    ::attack( theWeapon, nrOfHand );
}

