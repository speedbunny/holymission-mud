#include "../defs.h"

inherit "/obj/monster";

int clones;
    
void reset( int arg ) {
  object ob;

  clones = 0;
  ::reset( arg );
  if( arg ) return;

  set_name( "bagor the lich" );
  set_alias( "bagor" );
  set_alt_name( "lich" );
  set_short( "Bagor the lich" );
  set_long( "Bagor looks like the skeleton of a once rich fighter. It wears "
    + "an expensive set of armour and wields an impressive flaming sword. "
    + "It looks in a much better condition than you average wandering "
    + "skeleton and it's empty eyes radiate pure evil.\n" );
  set_level( 60 );
  set_hp( query_max_hp() + 1000 );
  set_str( 120 );
  set_dex( 120 );
  set_al( -1000 );
  set_ac( 20 );
  set_wc( 50 );
  set_aggressive( 1 );
  set_race( "undead" );
  set_chance( 10 );
  set_spell_mess1( "The lich Bagor casts a fireball at its opponent." );
  set_spell_mess2( "You are burnt by a fireball cast by the lich Bagor." );
  set_spell_dam( 100 );
  set_no_steal();

  ob = clone_object( "/obj/armour" );
  ob->set_name( "demonplate armour" );
  ob->set_alias( "demonplate" );
  ob->set_alt_name( "armour" );
  ob->set_short( "A suit of demonplate armour" );
  ob->set_long( "It is a red suit of plate mail like armour made from "
    + "demon skin, decorated with many flame symbols.\n" );
  ob->set_type( "armour/leg/arm" );
  ob->set_ac( 10 );
  ob->set_weight( 7 );
  ob->set_value( 10000 );
  transfer( ob, this_object() );
  init_command( "wear demonplate" );

  ob = clone_object( ITEM_DIR + "fsword" );
  transfer( ob, this_object() );
  init_command( "wield sword" );

  ob = clone_object( ITEM_DIR + "pstaff" );
  transfer( ob, this_object() );
  init_command( "wield staff" );
}

int hold( object caller, int time ) {
  if( random( 2 ) ) ::hold( caller, time );
  else ::hold( caller, 0 );
}

varargs int attack( object theWeapon, int nrOfHand ) {
  if( ::attack( theWeapon, nrOfHand ) )
    ::attack( theWeapon, nrOfHand );
}

int detect_invis() {
  return 1;
}

void heart_beat() { 
  string slave;

  if( query_hp() < 1000 && clones < 6 ) {
    switch( random( 4 ) ) {
      case 0:   slave = "banshee";      break;
      case 1:   slave = "shade";        break;
      case 2:   slave = "giantzom";     break;
      case 3:   slave = "druj";         break;
    }
    clones++;
    tell_room( environment(),
      "The lich Bagor utters the words 'PAGUNOW!'\n" );
    clone_object( MON_DIR + slave )->move_player( "X", environment(), 1,
      "steps out of a flickering gate.\n" );
  }
  else if( query_hp() < 2000 && clones < 3 ) {
    clones++;
    tell_room( environment(),
      "The lich Bagor utters the words 'PAGUNOW!'\n" );
    clone_object( MON_DIR + "mummy" )->move_player( "X", environment(), 1,
      "steps out of a flickering gate.\n" );
  }
  ::heart_beat();
}
