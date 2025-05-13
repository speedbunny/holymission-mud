#include  "../defs.h"

inherit "obj/monster";

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;
  set_name( "dragon skeleton" );
  set_alias( "skeleton" );
  set_alt_name( "dragon" );
  set_short( "A dragon skeleton" );
  set_long( "This is the animated skeleton of a dead dragon.\n" );
  set_level( 50 );
  set_race( "undead" );
  set_al( -500 );
  set_ac( 30 );
  set_wc( 50 );
  set_aggressive( 1 );
  set_number_of_arms( 4 );
  set_chance( 33 );
  set_spell_mess1( "The dragon skeleton breathess a lightning bolt at his "
    + "opponent." );
  set_spell_mess2( "The dragon skeleton breathes lightning at YOU!!!" );
  set_spell_dam( 200 );
}
