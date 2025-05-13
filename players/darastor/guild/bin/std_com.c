/* command:     say, shout, tell, whisper
 * syntax:      as in standard player comamnds
 * function:    modifies sentence to speak to use barbarian accent
 */

#include <lw.h>

int main( string str ) {
  string verb, msg;
  int res;
  
  verb = query_verb();
  if(!str) str = "";
  if( verb[0..0] == "'" ) {
    verb = "say";
    str = extract( verb, 1 ) + " " + str;
  }
  if( !str ) {
    notify_fail( capitalize( verb ) + " what?\n" );
    return 0;
  }
  switch( verb ) {  
    string *tmp;

    case "say":
      msg = present( "guildsoul", this_player() )->parse_string( str )
        + "\n";
      say( lw( sprintf( "%s says: %s", 
        this_player()->query_name(), msg ) ) );
      writelw( sprintf( "You say: %s", msg ) );
      res = 1;
    break;
#if 0
    case "shout":
      msg = present( "guildsoul", this_player() )->parse_string( str )
        + "\n";
      res = (int)this_player()->shout_to_all( msg );
    break;
#endif // 0
    case "whisper":
      tmp = explode( str, " " );
      if( sizeof( tmp ) < 2 ) {
        notify_fail( "Whisper whom what?\n" );
        return 0;
      }
      msg = present( "guildsoul", this_player() )->
        parse_string( implode( tmp[1..sizeof( tmp ) - 1], " " )  )+ "\n";
      res = (int)this_player()->whisper( tmp[0] + " " + msg );
    break;
    case "tell":
      tmp = explode( str, " " );
      if( sizeof( tmp ) < 2 ) {
        notify_fail( "Tell whom what?\n" );
        return 0;
      }
      msg = present( "guildsoul", this_player() )->
        parse_string( implode( tmp[1..sizeof( tmp ) - 1], " " )  )+ "\n";
#if 0
// Sauron: New tell command in the bin system...
      res = (int)this_player()->tell_player( tmp[0] + " " + msg );
#else
      res = (int)"/sys/bin/player/tell"->main(tmp[0]+" "+msg);
#endif // 0
    break;
  }
  return res;
}
