/* File:        /players/uglymouth/recoding/sherman/item/vcurse.c
 * Created:     Uglymouth, 971111.
 * Goal:        Simulating limited aspects of vampirism for players.
 *              At least every 15 minutes a cursed player needs to suck
 *              blood from another living of lose 1 point of con. Sucking
 *              blood drains hp from the victim. Npc-s attack, Fellow
 *              players risk being infected themselves. Sucking blood
 *              prevents losing con and may even restore lost con.
 */
#include "defs.h"
#define  CALL_FACTOR 60

int blood_level, drain_level;

void reset( int arg ) {
  if( arg ) return;
  drain_level = 0;
  blood_level = 15;
  call_out( "init_arg", 1, "15 0" );
}

int id( string str ) {
  return str == "vampire_curse";
}

string query_auto_load() {
  blood_level = ( 15 * CALL_FACTOR - find_call_out( "drain_con ) /
    CALL_FACTOR;
  return PATH + "vcurse:" + blood_level + " " + drain_level;
}

void init_arg( string arg ) {
  sscanf( "%d %d", blood_level, drain_level );
  environment()->set_stat_modifier( "con", -drain_level );
  if( find_call_out( "drain_con" ) == -1 )
    call_out( "drain_con", blood_level * CALL_FACTOR );
}

void init() {
  tell_object( environment(),
    "You feel a very strong urge to suck blood from someone.\n" );
  add_action( "do_suck", "suck" );
}

string extra_look() {
  return " has grown prolonged canine teeth.\n";
}

void drain_con() {
  blood_level -= 15;
  if( blood_level > 0 ) return;
  blood_level = 0;
  drain_level++;
  environment()->set_stat_modifier( "con", -drain_level );
  environment()->heal_self( 0 ); // Adjust hp to new max_hp if necessary.
  tell_object( environment(),
    "You have been without fresh blood for too long. You feel weakened.\n" );
}

int do_suck( string str ) {
  string what, whom;
  object whom_ob;

  if( !str || sscanf( str, "%s from %s", what, whom ) != 2 ) {
    notify_fail( "Suck what from whom?\n" );
    return 0;
  }
  if( what != "blood" ) {
    notify_fail( "Your eyes are filled with visions of tasty blood!\n" );
    return 0;
  }
  if( !( whom_ob = present( whom, environment( this_player() ) ) ) ) {
    notify_fail( "You don't see " + whom + " here.\n" );
    return 0;
  }
  if( !living( whom_ob ) || (string)whom_ob->query_race() == "undead" ) {
    notify_fail( "But " + whom + " will not satisfy your craving "
      + "for blood!\n" );
    return 0;
  }
  whom_ob->hit_player( (int)this_player()->query_level(), 7 );
  blood_level += (int)whom_ob->query_level();
  if( drain_level ) {
    drain_level--;
    environment()->set_stat_modifier( "con", -drain_level );
  }
  printf( "You bite %s in the neck and suck blood. Ah, you feel better "
    + "now.\n", capitalize( whom ) );
  say( sprintf( "%s bites %s in the neck and sucks blood.\n",
    this_player()->query_name(), capitalize( whom ) ), this_player() );
  if( whom_ob->query_npc() ) {
    printf( "%s doesn't take kindly to your bite and attacks!\n" );
    whom_ob->attack_ob( this_player() );
  }
  else {
    if( !random( 5 ) )
      move_object( clone_object( ITEM_DIR + "vcurse" ), whom_ob );
    printf( "You suspect that you may have infected " + capitalize( whom )
      + "with the vampire curse now.\n" );
  }
  return 1;
}

