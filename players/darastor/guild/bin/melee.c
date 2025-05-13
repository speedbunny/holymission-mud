/* command:     melee
 * syntax:      melee
 * function:    hit all possible targets in combat
 */

#include <lw.h>

int main() {
  object tmp;

  if( this_player()->query_ghost() ) {
    notify_fail( "You better pray you can do this some other time.\n" );
    return 0;
  }
  if( present( "combat_soul", this_player() ) ) {
    notify_fail( "You can't go into a melee while in barbarian combat!\n" );
    return 0;
  }
  if( this_player()->query_melee() ) {
    notify_fail( "You already are in a melee!\n" );
    return 0;
  }
  if( !( tmp = (object)this_player()->query_attack() ) ||
      !present( tmp, environment( this_player() ) ) ) {
    notify_fail( "You're not attacking anything!\n" );
    return 0;
  }
  if( (int)this_player()->query_sp() < 25 ) {
    notify_fail( "You are too braindead to do that.\n" );
    return 0;
  }
  else this_player()->restore_spell_points( -25 );
  printf( "You lose control of yourself and let a mad rage take over.\n" );
  say( lw( sprintf( "%s's eyes go out of focus and %s seems to lose "
    + "all control of %sself!\n", this_player()->query_short_name(),
    this_player()->query_pronoun(), this_player()->query_objective() ) ) );
  present( "guildsoul", this_player() )->de_equip();
  this_player()->start_melee();
  return 1;
}
