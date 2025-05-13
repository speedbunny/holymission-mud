/* command:     fpose
 * syntax:      fpose <message>
 * function:    fighter pose
 */

#include <lw.h>

#define CHK_SP(x) if((int)this_player()->query_sp() < x) {\
        write("You are too braindead to do that.\n"); return 1; }\
        else this_player()->restore_spell_points(-x)

string *busy_posing;

void reset( int arg ) {
  if( arg ) return;
  busy_posing = ({ });
}

int main( string str ) {

  if( member_array( this_player()->query_name(), busy_posing ) != -1 ) {
    notify_fail( "You're out of breath!\n" );
    return 0;
  }
  if( !str ) {
    CHK_SP( 30 );
    printf( "You raise your fist at the world in victory!\n" );
    shout( sprintf( "You can hear %s shouting in victory!\n",
      this_player()->query_short_name() ) );
    return 1;
  }
  CHK_SP( 75 );
  printf( "You raise your sword in victory.\n" );
  shout( sprintf( "%s shouts a victorous war cry! "
    + "can hear.\n", this_player()->query_short_name() ) );
  busy_posing += ({ this_player()->query_name() });
  call_out( "bellow_message", 2, str );
  return 1;
}

void bellow_message( string str ) {
  string msg;
  object guildsoul;

  if( !find_player( busy_posing[0] ) ) {
    busy_posing -= ({ busy_posing[0] });
    return;
  }
  guildsoul = present( "guildsoul", find_player( busy_posing[0] ) );
  msg = guildsoul->parse_string( str );
  printf( "You shout: %s\n", msg );
  shout( lw( sprintf( "%s shouts: %s\n",
    capitalize( busy_posing[0] ), msg ) ) );
  busy_posing -= ({ busy_posing[0] });
}
