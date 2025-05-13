/* command:     beep
 * syntax:      beep <guild master>
 * function:    attract the attention of the guild master
 */

#define GUILDMASTER     "darastor"
#define GM              capitalize( GUILDMASTER )

int main( string str ) {
  object gm;

  if( !this_player()->query_immortal() && str != GUILDMASTER ) {
    write( "Sorry, but you only can beep " + GM + ".\n" );
    return 1;
  }
  gm = find_player( str );
  if( !gm ) {
    notify_fail( "Sorry, but " + capitalize( str )
      + " must either be invis, busy, or not on.\n" );
    return 0;
  }
  tell_object( gm, "\n\t<   BEEP   > "
    + capitalize( this_player()->query_real_name() )
    + " has beeped you for something!\n" );
  printf( "You beeped %s!\n", capitalize( str ) );
  return 1;
}
