/* command:     bellow
 * syntax:      bellow <message>
 * function:    barbarian shout
 */

#include <lw.h>

#define CHK_SP(x) if((int)this_player()->query_sp() < x) {\
        write("You are too braindead to do that.\n"); return 1; }\
        else this_player()->restore_spell_points(-x)

string *busy_bellowing;

void reset( int arg ) {
  if( arg ) return;
  busy_bellowing = ({ });
}

int main( string str ) {
/*
  write( "I'm sorry to have to notify you that this command "
    + "is temporarily out of use due to recoding. It will be back this "
    + "week. - Viking Lord Uglymouth.\n" );
  return 1;
*/
  if( member_array( this_player()->query_name(), busy_bellowing ) != -1 ) {
    notify_fail( "You're out of breath!\n" );
    return 0;
  }
  if( !str ) {
    CHK_SP( 30 );
    printf( "You bellow and howl at the world!\n" );
    shout( sprintf( "You can hear %s bellowing and howling at the world!\n",
      this_player()->query_short_name() ) );
    return 1;
  }
  CHK_SP( 75 );
  printf( "You start to bellow at the top of your voice.\n" );
  shout( sprintf( "%s bellows loudly, so loud the whole of Holy Mission "
    + "can hear.\n", this_player()->query_short_name() ) );
  busy_bellowing += ({ this_player()->query_name() });
  call_out( "bellow_message", 2, str );
  return 1;
}

void bellow_message( string str ) {
  string msg;
  object guildsoul;

  if( !find_player( busy_bellowing[0] ) ) {
    busy_bellowing -= ({ busy_bellowing[0] });
    return;
  }
  guildsoul = present( "guildsoul", find_player( busy_bellowing[0] ) );
  msg = guildsoul->parse_string( str );
  printf( "You bawl: %s\n", msg );
  shout( lw( sprintf( "%s bawls: %s\n",
    capitalize( busy_bellowing[0] ), msg ) ) );
  busy_bellowing -= ({ busy_bellowing[0] });
}
