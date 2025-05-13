/* command:     beat
 * syntax:      beat chest
 * function:    barbarian emote
 */

int main( string str ) {
  if( str != "chest" ) {
    notify_fail( "Don't try to be civilized - beating your chest "
      + "is much more impressive!\n" );
    return 0;
  }
  printf( "You beat your hands on your chest and let out a "
    + "bloodcurdling howl!\n" );
  say( sprintf( "%s beats %s hands on %s chest and lets out a "
    + "bloodcurdling howl!\n", this_player()->query_short_name(),
    this_player()->query_possessive(), this_player()->query_possessive() ) );
  return 1;
}
