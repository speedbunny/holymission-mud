
/* ################################################################
   #                                                              #
   #                    Mage knock door                           #
   #                                                              #
   ###############################################(C) Llort########
 * Uglymouth 971212: Adapted code to allow using /room/doorroom.c
 *                   At the same time updated code efficiency a bit.
 */
#include <doorroom.h>
#include "/spells/spell.h"

inherit "/spells/spell";

int knock_old_door( string str, object door, int act_skill, int max_skill );
int knock_inheritable_door( string str, int act_skill, int max_skill );

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;

  set_name( "knock door" );
  set_kind( NO_COMBAT );
  set_syntax( "cast 'knock door' [door]" );
  set_guild_allowed( 5, 8 );
  set_save_vs( NO_SAVE );
  set_cost( 40 );
  set_player_help( "This spell will magically cause locked doors to unlock. "
    + "However, this spell will not work on all doors, since some have "
    + "been magically protected from this spell." );
}

int speed( int lev ) {
  if( lev > 20 ) return -1;
  if( lev > 10 ) return 0;
  return 1;
}

void release_spell( string str, int act_skill, int max_skill ) {
  object door;
  string dest, *all_doors;

  if( !str ) {
    printf( "Knocking on heaven's door?\n" );
    return;
  }

  if( !( door = present( str, environment( this_player() ) ) ) ) {
    all_doors = environment( this_player() )->query_doors();
    if( !all_doors ) {
      printf( "Your spell fizzles as it cannot find its target.\n" );
      return;
    }
    if( member_array( str, all_doors ) == -1 ) {
      printf( "Your spell fizzles as it cannot find its target.\n" );
      return;
    }
    knock_inheritable_door( str, act_skill, max_skill );
    return;
  }
  if( str != "door" && sscanf( str, "%s door", dest ) !=1 ) {
    printf( "Your spell fizzles as it cannot find its target.\n" );
    return;
  }
  if( str == "door" && door->number_of_doors() != 1 ) {
    door->which_door();
    return;
  }
  knock_old_door( str, door, act_skill, max_skill );
}

void knock_old_door( string str, object door, int act_skill, int max_skill ) {
  if( !door->query_locked() ) {
    printf( "Your spell fizzles on the unlocked door.\n" );
    say( sprintf( "%s tries to cast a spell at the %s but fails.\n",
      this_player()->query_name(), str ) );
    return;
  }
  if( !check_success( act_skill, max_skill ) ) return;
  printf( "The lock glows bright for a moment.\n" );
  say( sprintf( "The lock on the %s glows bright for a moment.\n", str ) );
  door->set_locked( 0 );
  if( door = door->query_partner_door() )
    door->set_locked( 0 );
}

void knock_inheritable_door( string str, int act_skill, int max_skill ) {
  object where;

  where = environment( this_player() );
  if( where->query_lock_status( str ) == DOOR_UNLOCKED ) {
    printf( "Your spell fizzles on the unlocked door.\n" );
    say( sprintf( "%s tries to cast a spell at the %s but fails.\n",
      this_player()->query_name(), str ) );
    return;
  }
  if( !check_success( act_skill, max_skill ) ) return;
  printf( "The lock glows bright for a moment.\n" );
  say( sprintf( "The lock on the %s glows bright for a moment.\n", str ) );
  where->set_lock_status( str, DOOR_UNLOCKED );
  call_other( where->query_other_door( str ), "set_lock_status", str,
    DOOR_UNLOCKED );
}
