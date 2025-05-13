#include "../defs.h"

#define COFFINS ({\
  ROOM_DIR + "room0",\
  ROOM_DIR + "room1",\
  ROOM_DIR + "room2",\
  ROOM_DIR + "room3",\
  ROOM_DIR + "room4",\
  ROOM_DIR + "room5",\
  ROOM_DIR + "room6",\
  ROOM_DIR + "room7",\
  ROOM_DIR + "room8",\
  ROOM_DIR + "room9",\
})

inherit "/obj/monster";

string *coffins, killed_by;
int    current_coffin;

void reset( int arg ) {
  if( !present( "ring of regeneration", this_object() ) ) {
    transfer( clone_object( ITEM_DIR + "regring" ), this_object() );
    init_command( "wear ring" );
    init_command( "twist ring" );
  }
  if( !present( "flaming sword", this_object() ) {
    transfer( clone_object( "players/sherman/swords/sword1", this_object() );
    init_command( "wield sword" );
  }
  ::reset( arg );
  if( arg ) return;

  set_name( "sashya the vampire count" );
  set_alias( "sashya" );
  set_short( "Sashya the vampire count" );
  set_long( "Lord Sashya the vampire count.\n");
  set_level( 80 );
  set_gender( 1 );
  set_max_hp( query_max_hp()+1000 );
  set_hp( query_max_hp() );
  set_al( -1000 );
  set_ac( 25 );
  set_chance( 20 );
  set_spell_mess1( "Count Sashya's touch drains his opponent's "
    + "very soul.\n" );
  set_spell_mess2( "Count Sashya's touch drains your very soul!\n");
  set_spell_dam( 120 );
  set_dead_ob( this_object() );
  set_dodge(25);
  coffins = allocate( 3 );
  current_coffin = 0;
  set_coffins();
}

/* USERDOC:
 * This effectively means that people going for the vampire quest may
 * not be aided by people who have already solved this quest. Tough job.
 */
void init() {
  ::init();
  if( !this_player()->query_quest( "vampirequest" ) ) return;
  printf( "Lord Sashya flees in terror as he sees you ready to slay "
    + "him once again.\n" );
  say( sprintf( "Lord Sashya flees in terror as he sees his old conqueror "
    + "%s ready to slay him again.\n", this_player()->query_short_name() );
  destruct( this_object() );
}

void set_coffins() {
  coffins[0] = COFFINS[ random( 10 ) ];
  do coffins[1] = COFFINS[ random( 10 ) ];
    while( coffins[1] == coffins[0];
  do coffins[2] = COFFINS[ random( 10 ) ];
    while( coffins[2] == coffins[0] || coffins[2] == coffins[1] );
}

string *query_coffins( int i ) {
  if( !i ) return coffins;
  return coffins[i];
}

void revive() {
  heal_self( 10000 );
  move_player( "X#" + query_create_room() );
}

int monster_died( object ob ) {
  move_to_coffin();
  return 1;
}

varargs int attack( object theWeapon, int nrOfHand ) {
  if( (int)query_attack()->query_level() < 15 ) {
    printf( "Lord Sashya doesn't deem you a worthy opponent and "
      + "dismisses you with a magic gesture of his hand.\n"
      + "Suddenly you find yourself somewhere else...\n" );
    say( sprintf( "Lord Sashya doesn't deem %s a worthy opponent and "
      + "dismisses %s with a magic gesture of his hand.\n",
      (string)query_attack()->query_name(),
      (string)query_attack()->query_objective() ), query_attack() );
    query_attack()->move_player( "X#room/church" );
    return 0;
  }
  if( ::attack( theWeapon, nrOfHand ) )
    if( ::attack( theWeapon, nrOfHand ) )
      ::attack( theWeapon, nrOfHand );
}

void run_away() {
  printf( "You cannot scare away Count Sashya that easily.\n" );
}

void move_to_coffin() {
#ifndef DEBUG
  if( previous_object() != this_object() &&
    !previous_object()->id( "count_sashya_coffin" ) ) return;
#endif
  if( current_coffin == 2 ) {
    if( (string)this_player()->query_real_name() != killed_by ) {
      printf( "When you look around the ashes, you have a somewhat "
        + "disappointed feeling. It seems that the evil vampire Count "
        + "Sashya is really gone for now. But you wonder how much better "
        + "it would have felt if you would have killed Count Sashya "
        + "in combat yourself first.\n" );
      return;
    }
    printf( "As the smoke clears the air now really feels free of any "
      + "evil presence.  You feel relieved, joyful even for the destruction "
      + "of such a great evil power!! Finally you realise that these lands "
      + "even may become green and fertile again when Time wipes out the "
      + "last traces of this evil episode. You feel like you can return "
      + "home a hero. Hail thee, Slayer of Evil!\n" );
    say( sprintf( "%s has destroyed the evil vampire Count Sashya for "
      + "good!\n", this_player()->query_short_name() ), this_player() );
    this_player()->set_quest( "vampirequest" );
    destruct( this_object() );
    return;
  }
  if( !find_object( coffins[ current_coffin ] ) ) {
    call_other( coffins[ current_coffin ]. "???" );
  find_object( coffins[ current_coffin ] )->set_count_coffin();
  if( find_call_out( "revive" ) ) remove_call_out( "revive" );
  call_out( "revive", 900 );
  if( !current_coffin ) {
    killed_by = this_player()->query_real_name();
    printf( "You killed the evil vampire Count Sashya.\nOr did you...\n" );
    tell_room( environment(), "As Count Sashya is dealt a mortal blow, he "
      + "suddenly dissolves into a cloud of sickly grey gas. A sudden gust "
      + "of wind blows him away from here to an unknown destination.\n" );
  }
  else printf( "As the fire dies, you feel a weak evil power slowly "
    + "concentrate from the smoke. A vaguely batlike shape forms out of "
    + "the mist and flies away over your head.\n" );
  current_coffin++;
}

