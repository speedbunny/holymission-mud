#include "../defs.h"

inherit "obj/monster";

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;
  set_name( "mummy" );
  set_short( "A mummy" );
  set_long( "This undead creature wrapped in old cloth staggers slowly "
    + "but inevitably towards you. The touch of its mouldy hands is "
    + "something to be avoided at all cost.\n");
  set_level( 10 );
  set_race( "undead" );
  set_al( -150 );
  set_ac( 7 );
  set_wc( 15 );
  set_aggressive( 1 );
  set_dead_ob( this_object() );
  add_money( 101 + random( 100 ) );
}

void init() {
  ::init();
  add_action( "do_burn", "burn" );
  add_action( "do_burn", "light" );
}

int monster_died( object ob ) {
  tell_room( environment(),
    "The mummy falls apart in loose strands of dirty cloth.\n" );
  destruct( this_object() );
  return 1;
}

varargs int attack( object theWeapon, int nrOfHand ) {
  if( random( (int)query_attack()->query_dex() ) ) {
    query_attack()->add_poison( random( 5 ) + 1 );
    tell_object( query_attack(), "You feel poison dripping from the mummy's touch.\n" );
  }
  return ::attack( theWeapon, nrOfHand );
}

int do_burn( string str ) {
  object torch;

  if( !id( str ) ) return 0;
  if( !( torch = present( "torch", this_player() ) ) ) {
    notify_fail( "You don't have a torch!\n" );
    return 0;
  }
  if( !torch->query_lighted() ) {
    notify_fail( "Burn something with an extinguished torch???\n" );
    return 0;
  }
  printf( "The dry cloth of the mummy catches fire and with a bright "
    + "green shooting flame it is consumed by the fire completely.\n" );
  say( sprintf( "The mummy goes up an one big green shooting flame as %s "
    + "sets it on fire.\n", this_player()->query_short_name() ),
    this_player() );
  destruct( this_object() );
  return 1;
}

