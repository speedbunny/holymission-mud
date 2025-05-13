/* command:     prepare
 * syntax:      prepare for barbarian combat
 * function:    allows multiple attack commands per round
 */

#include <lw.h>

#define COMBAT_SOUL "/players/darastor/guild/soul_archive/combat_soul"

int main( string str ) {
    object comb_soul;

    if( str!="for barbarian combat" ) return 0;
    if( this_player()->query_ghost() ) {
	notify_fail( "You have no physical shell to prepare for combat.\n" );
	return 0;
    }
    if( present( "combat_soul", this_player() ) ) {
	notify_fail( "But you already are in barbarian combat!\n" );
	return 0;
    }
    if( this_player()->query_melee() ) {
	notify_fail( "You can't prepare for barbarian combat while in "
	  + "a melee!\n" );
	return 0;
    }
    if( (int)this_player()->query_sp() < 40 ) {
	notify_fail( "You are too braindead to do that.\n" );
	return 0;
    }
    else this_player()->restore_spell_points( -40 );
    printf( "You prepare for barbarian combat.\n" );
    /*
      say( lw( sprintf( "%s suddenly stretches %s body and starts to flex "
	+ "%s muscles. As %s does this, %s lets out a loud howl and %s "
	+ "eyes start to go out of focus. You realize that %s is "
	+ "performing the old rituals of barbarian combat.\n" ),
	this_player()->query_short_name(), this_player()->query_possessive(),
	this_player()->query_possessive(), this_player()->query_pronoun(),
	this_player()->query_short_name(), this_player()->query_possessive(),
	this_player()->query_pronoun() ) ), this_player() );
    */
    present( "guildsoul", this_player() )->de_equip();
    comb_soul = clone_object( COMBAT_SOUL );
    move_object( comb_soul, this_player() );
    present( "guildsoul", this_player() )->set_combat_soul( comb_soul );
    return 1;
}
