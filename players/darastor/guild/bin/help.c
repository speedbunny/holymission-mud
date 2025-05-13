/* command:     help
 * syntax:      help <levels|legendlevels|guild>
 * function:    provide help on guild related matters
 */

#define GM              "guild/master"
#define GUILD_HELP_FILE "/players/darastor/guild/TEXT/help.txt"

int main( string str ) {
  if( str != "levels" && str != "legendlevels" && str != "guild" )
    return 0;
  switch( str ) {
    case "levels":
      GM->list_levels( 11, (int)this_player()->query_gender() );
      return 1;
    case "legendlevels":
      GM->list_legend_levels( 11, (int)this_player()->query_gender() );
      return 1;
    case "guild":
      this_player()->more_string( read_file( GUILD_HELP_FILE ) );
      return 1;
    default:
      return 0;
  }
}
