/* command:     greet
 * syntax:      greet <player>
 * function:    barbarian emote
 */

int main( string str ) {
  object who;

  if( !str ) return 0;
  who = present( str, environment( this_player() ) );
  if( !who || !interactive( who ) ||
      who->query_guild() == this_player()->query_guild() ) {
    notify_fail( capitalize( str ) + " is not a member of the Horde!\n" );
    return 0;
  }
  printf( "You smash your forehead into the skull of %s in the greeting "
    + "of the Horde!\n", capitalize( str ) );
  tell_object( who, sprintf( "Barbarian %s slams %s forehead into your "
    + "skull in the secret greeting of the Horde!\n",
    this_player()->query_short_name(), this_player()->query_possessive() ) );
  say( sprintf( "%s smashes %s forehead into the skull of %s!\n",
    this_player()->query_short_name(), this_player()->query_possessive(),
    capitalize( str ) ), who );
  return 1;
}
