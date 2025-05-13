#include "../defs.h"

inherit "/obj/monster";

int clones;

void reset( int arg ) {
  object ob;

  ::reset(arg);
  clones=0;
  if( arg ) return;

  set_name( " gazot the lich" );
  set_alias( "gazot" );
  set_alt_name( "lich" );
  set_short( "Gazot the lich" );
  set_long( "Gazot looks like the skeleton of a once rich mage. It wears "
    + "an expensive set of robes and a jet black pointy mage's hat. "
    + "It looks in a much better condition than you average wandering "
    + "skeleton and it's empty eyes radiate pure evil.\n" );
  set_level( 150 );
  set_race( "undead" );
  set_hp( 50000 );
  set_al( -1500 );
  set_wc( 150 );
  set_aggressive( 1 );

  transfer( clone_object( ITEM_DIR + "swordolb" ), this_object() );

  transfer( clone_object( ITEM_DIR + "refring" ),this_object() );

  ob = clone_object( "/obj/treasure" );
  ob->set_name( "sun crystal" );
  ob->set_alias( "crystal" );
  ob->set_short( "A shining Sun Crystal" );
  ob->set_long( "One of the very rare Sun Crystals. It shines with the "
    + "light from the sun itself.\n" );
//  ob->set_weight( 1 );
  ob->set_light( 15 );
  ob->set_value( 3000 );
  transfer( ob, this_object() );

  add_money( 10001 + random( 10000 ) );
}

varargs int attack( object theWeapon, int nrOfHand ) {
  if( ::attack( theWeapon, nrOfHand ) ) {
    if( !random( 5 ) )
      init_command( ({ "missile", "shock", "fireball" })[ random( 3 ) ] );
    if( ::attack( theWeapon, nrOfHand ) ) {
      if( !random( 5 ) )
        init_command( ({ "missile", "shock", "fireball" })[ random( 3 ) ] );
      ::attack( theWeapon, nrOfHand );
    }
  }
}

int detect_invis() {
  return 1;
}

int hold( object caller, int time ) {
  printf( "Gazot waves your puny spell aside with a mere hand gesture.\n" );
  return 0;
}

void heart_beat() { 
  if( query_hp() < 30000 && !clones  ) {
    clones++;
    tell_room( environment(),
      "The lich Gazot utters the words 'PAGUNOW!'\n" );
    clone_object( MON_DIR + "giantzom" )->move_player( "X", environment(), 1,
      "steps out of a flickering gate.\n" );
  }
  if( query_hp() < 5000 && clones < 2 ) {
    clones++;
    tell_room( environment(),
      "The lich Gazot utters the words 'PAGUNOW!'\n" );
    clone_object(  MON_DIR + "druj" )->move_player( "X", environment(), 1,
      "steps out of a flickering gate.\n" );
  }
  ::heart_beat();
}
