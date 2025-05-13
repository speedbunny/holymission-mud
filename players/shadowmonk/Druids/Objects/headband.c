inherit "/obj/armour";
#include "../Include/druids.h"

int rate;
static object owner;

void reset( status b ) {
  ::reset( b );
  if( b )
    return;
  owner = TP;
  rate = ( TP->LEVEL + TP->LLEVEL ) / 5;
  set_name( "headband" );
  set_alias( "band" );
  set_short(
    "A silver shimmering headband"
  );
  set_long(
    "The band is made of silver with a lot of magical runes "+
    "engraved along. It is radiating magic.\n"
  );
  set_type( "helmet" );
  set_weight( 1 );
  set_value( 1 );
  set_ac( 1 );
}

void heart_beat() {
  if( !ENVF || !interactive( ENVF ) || !owner ) {
    disable_commands();
    destruct( TO );
  }
  else if( query_worn() )
    owner->ADDSP( rate + 2 );
}

status wear( string s ) {
  if( s != "headband" )
    return 0;
  if( !owner || owner != TP )
    notify_fail( "This is not your headband.\n" );
  else if( ::wear( s ) )
    if( owner->RGUILD == GNUM ) {
      write( "You feel the power of nature.\n" );
      enable_commands();
      set_heart_beat(1);
      return 1;
    }
  return 0;
}

status remove( string s ) {
  if( id( s ) && WORN )
    if( owner->RGUILD == GNUM ) {
       write( "The power of nature leaves your body.\n" );
       set_heart_beat(0);
       disable_commands();
    }
  return ::remove( s );
}
