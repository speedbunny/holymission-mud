#include "../defs.h"

inherit "obj/monster";

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;
  set_name( "druj skull" );
  set_alias( "druj" );
  set_alt_name( "skull" );
  set_short( "A druj skull" );
  set_long( "This floating skull is one of the most feared of the undead. "
    + "It radiates a sickly purplish light from its empty eye sockets. "
    + "It's bytes is known to be both poisonous and paralyzing. But most "
    + "of all, it's reputed to be terrifyingly fast.\n" );
  set_level( 45 );
  set_str( 60 );
  set_dex( 60 );
  set_race( "undead" );
  set_al( -500 );
  set_ac( 25 );
  set_aggressive( 1 );
  set_number_of_arms( 6 );
  set_wc( 30 );
  set_chance( 15 );
  set_spell_mess1( "The druj skull bites its opponent hard." );
  set_spell_mess2( "The druj skull bites you hard." );
  set_spell_dam( 60 );
}
