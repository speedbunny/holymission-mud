#include "/players/gareth/define.h"
#define BERZERK_LEVEL 18
#define BERZERK_COST 40
#define THREE_ATTACK 23
#define FOUR_ATTACK 29
#define SHADOW "/players/exos/gareth/berzerk_shad"

status berzerk() {
    object shadow, here;
    int lasting, att;

    if( this_player() -> query_ghost() ) {
	write( "\
You suddenly realize that this was a great mistake.\n\
The whole room is spinning around you.\n\
You decide to run as far as you can to leave this place.\n" );
	this_player() -> run_away();
	this_player() -> run_away();
	write("As you feel your mind clearing you decide to rest for a moment.\n");
	return ( 1 );
    }

    if( this_player() -> query_level() < BERZERK_LEVEL ) {
	write( "You are not strong enough yet.\n" );
	return ( 1 );
    }

    if( !this_player() -> query_attack() ) {
	write( "But you are not fighting anyone.\n" );
	return ( 1 );
    }
    if( this_player() -> berzerk_shad() ) {
	write( "You are as berzerk as anyone can be.\n" );
	return ( 1 );
    }
    if( this_player() -> block_shad() ) {
	write( "You cannot berzerk whilst you are blocking.\n" );
	return ( 1 );
    }

    if( this_player() -> query_spell_points() < BERZERK_COST ) {
	write("You are too tired to go berzerk.\n");
	return ( 1 );
    }

    switch( this_player() -> query_level() ) {
    case BERZERK_LEVEL .. ( THREE_ATTACK - 1 ):
	att = 2;
	break;
    case THREE_ATTACK .. ( FOUR_ATTACK - 1 ):
	att = 3;
	break;
    default:
	att = 4;
    }
    write( "You turn into a rampaging FRENZY!!!\n" );
    this_player() -> restore_spell_points( -BERZERK_COST );
    say( this_player() -> query_name() + " turns into a raging berzerker!!!\n",
      this_player() );
    lasting = ( 50 + this_player() -> query_level() + this_player() -> query_con() );
    here = environment( this_player() );
    shadow = clone_object( SHADOW );
    shadow -> start_shadow( this_player(), lasting, here, att );
    return ( 1 );
}
