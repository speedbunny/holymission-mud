#include "../Include/druids.h"

status check_cast( string *args ) {
  int i, l, c;
  object ob;
  i = sizeof( args );
  TME( "sizeof " + i );
  if( ( i != 3  ) && ( i != 5 ) ) {
    write( "Syntax: cast cure <type> wounds <on <player>>\n" );
    return 0;
  }
  TME( args[1] + " " + args[2] );
  if( ( args[1] != "light" && args[1] != "serious" && args[1] != "critical" ) ||
      ( args[2] != "wounds" ) ) {
    write( "Syntax: cast cure <type> wounds <on <player>>\n" );
    return 0;
  }
  ob = i == 5 ? PRES( args[4], ENV( TP ) ) : TP;
  if( i == 5 ) {
    if( args[3] != "on" ) {
      write( "Syntax: cast cure <type> wounds <on <player>>\n" );
      return 0;
    }
    if( !ob ) {
      write( "Cure " + args[ 1 ] + " wounds of who?\n" );
      return 0;
    }
    if( !living( ob ) ) {
      write("Doh, don't be an idiot.\n");
      return 0;
    }
  }
  switch( args[ 1 ] ) {
    case "light"    : l =  1; c = 30; break;
    case "serious"  : l =  8; c = 50; break;
    case "critical" : l = 16; c = 70; break;
  }
  if( TP->query_ghost() )
    write( "You can't seem to cast that in your current state.\n" );
  else if( ( TP->LEVEL + TP->LLEVEL ) < l )
    write( "You are not experienced enough to cast that.\n" );
  else if( TP->SP < c )
    write( "Your mind is to weak to cast that.\n" );
  else
    return( 1 );
  return( 0 );
}

int spell_delay( string *args ) {
  switch( args[ 1 ] ) {
    case "light"    : return 10; break;
    case "serious"  : return 11; break;
    case "critical" : return 11; break;
  }
}

status execute_cast( string *args ) {
  int i, h, c;
  object ob;
  ob = ( i = sizeof( args ) ) == 5 ? PRES( args[4], ENV( TP ) ) : TP;
  switch( args[ 1 ] ) {
    case "light"    : h = 2 * ( random( 40 ) + 1 ) + TP->LEVEL; c = 30; break;
    case "serious"  : h = 4 * ( random( 40 ) + 1 ) + TP->LEVEL; c = 50; break;
    case "critical" : h = 6 * ( random( 40 ) + 1 ) + TP->LEVEL; c = 70; break;
  }
  if( i == 3 ) {
    write( "You cast cure " + args[ 1 ] + " wounds on yourself.\n" );
    say( TP->NAME + " casts cure " + args[ 1 ] + " wounds on " + TP->OBJ + "self.\n");
  }
  else if( !PRES( args[ 4 ], ENV( TP ) ) ) {
    write( "Your spell is lost, as your target is no longer here with you.\n" );
    TP->ADDSP( c );
    return( 1 );
  }
  else {
    write( "You cast cure " + args[ 1 ] + " wounds on " + ob->NAME + ".\n" );
    say( TP->NAME + " casts cure " + args[ 1 ] + " wounds on " + ob->NAME + ".\n" );
    TELL( ob, TP->NAME + " casts cure " + args[ 1 ] + " wounds on you.\n");
  }
  ob->ADDHP( h );
  if( ob->HP > ob->MAXHP )
    ob->ADDHP( ob->HP - ob->MAXHP );
  TP->ADDSP( c );
  return( 1 );
}

