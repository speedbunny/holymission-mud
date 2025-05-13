#include "../defs.h"

inherit "obj/monster";

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;
  set_name( "banshee");
  set_short( "A banshee" );
  set_long( "This undead creature is all skin and bone. It has very vague "
    + "elven features, but its contorted face and wide coney lips make "
    + "you feel very uneasy to say the least.\n" );
  set_level( 20 );
  set_al( -150 );
  set_ac( 10 );
  set_wc( 20 );
  set_aggressive( 1 );
  set_race( "undead" );
  add_money( 201 + random( 200 ) );
}

varargs int attack( object theWeapon, int nrOfHand ) {
  int res;

  if( !( res = ::attack( theWeapon, nrOfHand ) ) ) return 0;
  if( !random( 10 ) ) {
    tell_object( query_attack(), "The banshee wails and strikes fear into "
      + "your heart. You flee in terror!\n" );
    query_attack()->run_away();
    tell_room( environment(), sprintf( "The banshee wails and fear strikes %s's heart. "
      + "%s runs away in terror.\n", query_attack()->query_short_name(),
      query_attack()->query_pronoun() ) );
  }
//  return ::attack( theWeapon, nrOfHand );
  return res;
}

