#include "../Include/druids.h"

status check_cast( string *args ) {
  if( TP->query_ghost() )
    write( "You can't seem to cast that in your current state.\n" );
  else if( TP->SP < 100 )
    write( "Your mind is to weak to cast that.\n" );
  else if( PRES( "band", TP ) )
    write( "Nah, one is enough.\n" );
  else
    return( 1 );
  return( 0 );
}

int spell_delay( string *args ) {
  return 0;
}

status execute_cast( string *args ) {
  object hb;
  write( "You kneel down and and ask mother nature for a gift.\n" );
  say( TP->NAME + " kneels down and asks mother nature for a gift.\n" );
  hb = clone_object( OBJS + "headband" );
  if( transfer( hb, TP ) ) {
    write( "You cannot seem to accept mother nature's gift.\n" );
    say( TP->NAME + " cannot accept mother nature's gift.\n");
    return( 1 );
  }
  write( "You receive a headband.\n" );
  say( TP->NAME + " receives a headband.\n");
  TP->ADDSP( -100 );
  return( 1 );
}

