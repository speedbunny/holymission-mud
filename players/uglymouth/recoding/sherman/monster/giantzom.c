#include "../defs.h"

inherit "obj/monster";

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;
  set_name( "giant zombie" );
  set_alias( "zombie" );
  set_short( "A giant zombie" );
  set_long( "Well, you've seen the type before... animated corpse, pale, "
    + "slowly decaying while roaming the earth, slow and too stupid to "
    + "get any job done. Only... you've never seen them this BIG!!!\n" );
  set_level( 40 );
  set_str( 60 );
  set_dex( 50 );
  set_al( -500 );
  set_size( 4 );
  set_ac( 20 );
  set_wc( 25 );
  set_aggressive( 1 );
  set_number_of_arms( 4 );
  set_race( "undead" );
  set_chance( 15 );
  set_spell_mess1( "The giant zombie clubs its opponent hard!" );
  set_spell_mess2( "The giant zombie clubs you hard!" );
  set_spell_dam( 50 );
}
