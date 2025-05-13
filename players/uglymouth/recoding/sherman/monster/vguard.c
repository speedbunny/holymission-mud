#include "../defs.h"

inherit GEN_VAMPIRE;

void reset( int arg ) {
  ::reset(arg);
  if( arg ) return;
  set_name( "vampire guard" );
  set_alias( "guard" );
  set_short( "A vampire guard" );
  set_long( "A typical example of one of the Vamire Lord's cursed and "
    + "enslaved minions. This now anonymous creature of undeath  still "
    + "is a powerful opponent. More so even than when he was alive. "
    + "His shadowy cape and black sword seem to exist only as shadows. "
    + "Nevertheless they predict nothing but death. And worse.\n" );
  set_level( 20 );
  set_gender( random( 2 ) + 1 );
  set_al( -250 );
  set_ac( 15 );
  set_wc( 40 );
}

