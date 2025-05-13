#include "../Include/druids.h"

status casting;
object cground;

void reset(status b ) {
  if( b )
    return;
//  casting = 0;
//  cground = ENV( TP );
}

void init() {
  add_action( "_cast", "cast"  );
  add_action( "_hook", "",   1 );
//  set_heart_beat( 1 );
}

status id( string s ) {
  return s == "druidsoul" || s == "guildsoul";
}

string short() {
  if( TP && TP->IMM )
    return( "Druid soul" );
  return( 0 );
}

void long() {
  write( "This is your druid guild soul.\n" );
}

status drop() {
  return 1;
}

status get() {
  return (1);
}

status execute_cast( string *args ) {
  args[ 0 ]->execute_cast( args );
  casting = 0;
  return 1;
}

status _cast( string s ) {
  string *args;
  if( !s || s == "" ) {
    write( "You must specify which spell you would like to cast.\n" );
    return 1;
  }
  args = explode( s, " " );
  s = args[ 0 ];
  args[ 0 ] = SPELLS + args[ 0 ];
  if( file_size( args[ 0 ] + ".c" ) > 0 ) {
    if( args[0]->check_cast( args ) )
      if( find_call_out( "execute_cast" ) == -1 ) {
        casting = 1;
        cground = ENV( TP );
        call_out( "execute_cast", args[0]->spell_delay( args ), args );
      }
      else
        write( "You are casting a spell already." );
  }
  else
    write( "You dont know a spell named '" + s + "'!\n" );
  casting = 0;
  return 1;
}

void pmoved( object ob ) {
  if( find_call_out( "execute_cast" ) != -1 ) {
    TME( "---Found a callout" );
    TME( "---" + file_name( ENV( TP ) ) );
    TME( "---" + file_name( ob ) );
    if( ENV( TP ) != ob ) {
      TME( "---Removing callout" );
      remove_call_out( "execute_cast" );
      write( "You lost your concentration casting your spell." );
    }
  }
}

status _hook( string s ) {
   TME( "---Hook" );
  if( find_call_out( "execute_cast" ) != -1 ) {
    TME( "---Found a callout" );
    TME( "---" + file_name( ENV( TP ) ) );
    TME( "---" + file_name( cground ) );
    call_out( "pmoved", 0, cground );
  }
  if( query_verb() == "destsoul" ) {
    destruct( TO );
    return 1;
  }
  return 0;
}

void guild_changes() {
  if( TP->bark_shadow() )
    TP->dest_me();
  if( TP->fireshield() )
    TP->dest_me();
  if( PRES( "flameblade", TP ) )
    destruct( PRES( "flameblade", TP ) );
  return;
}

