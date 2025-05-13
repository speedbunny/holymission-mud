/* command:     tattoo
 * syntax:      tattoo look
 *              tattoo change <type>
 *              tattoo position <location>
 *              tattoo show
 * function:    elaborate barbarian emote
 */

#include <lw.h>

int main( string str ) {
  string action, how;

  if( !str ) return 0;
  if( str != "show" && str != "look" &&
      sscanf( str, "%s %s", action, how ) != 2 ) {
    notify_fail( "Look, you can do a lot with tattoos, but "
      + "there are limits!\n" );
    return 0;
  }
  if( this_player()->query_ghost() ) {
    notify_fail( "You left your tattoo behind on your corpse!\n" );
    return 0;
  }
  if( str == "show" ) action = "show";
  if( str == "look" ) action = "look";

  switch( action ) {
    case "look":
      how = (string)this_player()->queryenv( "TATTOO" );
      if( !how )
        printf( "Your tattoo is currently a fairly ordinary one.\n" );
      else
        writelw( sprintf( "You are tattooed with %s on your %s.\n", how,
          ( (string)this_player()->queryenv( "TATTOOPOS" ) ?
            (string)this_player()->queryenv( "TATTOOPOS" ) : "body" ) ) );
    break;
    case "change":
      this_player()->setenv( "TATTOO", how );
      writelw( sprintf( "Your tattoo is now of %s.\n", how ) );
    break;
    case "show":
      how = (string)this_player()->queryenv( "TATTOO" );
      if( !how ) {
        printf( "You don't have a very exciting tattoo to show off.\n" );
        break;
      }
      writelw( sprintf( "You show off your tattoo of %s.\n", how ) );
      say( lw( sprintf( "%s shows off the tattoo of %s that is emblazoned "
        + "on %s %s.\n", this_player()->query_short_name(), how,
        this_player()->query_possessive(),
        ( (string)this_player()->queryenv( "TATTOOPOS" ) ?
          (string)this_player()->queryenv( "TATTOOPOS" ) : "body" ) ) ) );
    break;
    case "position":
      this_player()->setenv( "TATTOOPOS", how );
      writelw( sprintf( "Your tattoo is now placed on your %s.\n",
        how ) );
    break;
    default:
      notify_fail( "Hey, you can only take self-mutilation so far...\n" );
      return 0;
    break;
  }
  return 1;
}
