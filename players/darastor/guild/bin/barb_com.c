/* command:     grunt, howl, growl
 * syntax:      <grunt|howl|growl> <message>
 * function:    barbarian variations to the say command
 */

#include <lw.h>

int main( string str ) {
  object ob;
  string verb, parsed_msg;
    
  verb = query_verb();
  if( verb != "grunt" && verb != "howl" && verb != "growl" )
    return 0;
  if( !str ) {
    say( sprintf( "s %ss in a most barbaric manner.\n",
      this_player()->query_name(), verb ) );
    write( sprintf( "You %s in a most barbaric manner.\n", verb ) );
    return 1;
  }
  if( ob = present( str, environment( this_player() ) ) ) {
    say( lw( sprintf( "%s %ss at %s in a most barbaric manner.\n",
      this_player()->query_name(), verb, (string)ob->query_name() ) ) );
    writelw( sprintf( "You %s at %s in a most barbaric manner.\n",
      verb, (string)ob->query_name() ) );
    tell_object( ob,
      lw( sprintf( "%s %ss at you in a most barbaric manner.\n",
      this_player()->query_name(), verb ) ) );
    return 1;
  }
  if( ob = present( explode( str, " " )[0], 
      environment( this_player() ) ) ) {
    parsed_msg = (string)present( "guildsoul", this_player() )->
      parse_string( extract( str, strstr( str, " " ) + 1 ) );
    say( lw( sprintf( "%s %ss something incomprehensible at %s.\n",
      this_player()->query_name(), verb, (string)ob->query_name() ) ) );
    writelw( sprintf( "You %s: \"%s\" at %s.\n", 
      verb, parsed_msg, ob->query_name() ) );
    tell_object( ob, lw( sprintf( "%s %ss: \"%s\" at you.\n",
      this_player()->query_name(), verb, parsed_msg ) ) );
    return 1;
  }
  parsed_msg = (string)present( "guildsoul", this_player() )->
    parse_string( str );
  say( lw( sprintf( "%s %ss: %s\n",
    this_player()->query_name(), verb, parsed_msg ) ) );
  writelw( sprintf( "You %s: %s\n", verb, parsed_msg ) );
  return 1;
}
