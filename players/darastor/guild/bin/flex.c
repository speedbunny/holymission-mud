/* command:     flex
 * syntax:      flex muscles
 * function:    barbarian emote
 */

int main( string str ) {
  if( str && str != "muscles" ) {
    notify_fail( "Don't try looking too smart, barbarian!\n" );
    return 0;
  }
  printf( "You flex your muscles.\n" );
  say( sprintf( "%s flexes %s muscles.\n",
    this_player()->query_short_name(), this_player()->query_possessive() ) );
  return 1;
}
