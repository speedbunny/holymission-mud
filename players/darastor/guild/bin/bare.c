/* command:     bare
 * syntax:      bare teeth
 * function:    barbarian emote
 */

int main( string str ) {
  if( str != "teeth" ) {
    notify_fail( "What do you want to bare?!?\n" );
    return 0;
  }
  write( "You bare your teeth and look ready to eat someone alive!\n" );
  say( sprintf( "%s bares %s teeth and looks ready to eat you alive.\n",
    this_player()->query_short_name(), this_player()->query_possessive() ),
    this_player() );
  return 1;
}

