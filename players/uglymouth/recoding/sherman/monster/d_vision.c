#include "../defs.h"

inherit "obj/monster";

void reset( int arg ) {
  ::reset(arg);
  if (arg) return;

  set_name( "double vision" );
  set_alias( "vision" );
  set_short( "A double vision" );
  set_long( "This is a vision right out your worst nightmare. For some "
    + "reason it seems to be a bit out of focus though. As if it were "
    + "stereo visions that are not quite synchronised. Still just seeing "
    + "it sends the cold shivers down your spine.\n" );
  set_level( 16 + random( 5 ) );
  set_race( "undead" );
  set_al( -250 );
  set_wc( 12 );
  set_ac( 3 );
  set_trapped( 1 );
}

varargs int attack( object theWeapon, int nrOfHand ) {
  object ob;

  if( !::attack( theWeapon, nrOfHand ) ) return 0;
  ob = clone_object( explode( file_name( this_object() ), "#" )[0] );
  move_object( ob, environment( this_object() ) );
  tell_object( query_attack(), "At you hit the vision, it splits in half. "
    + "You just created ANOTHER vision. Out of surprise you stop fighting.\n" );
  say( sprintf( "As %s hits the vision, it splits in half. %s just created "
    + "ANOTHER vision and stops fighting.\n" , query_attack()->query_name(),
    query_attack()->query_pronoun() ), query_attack() );
  ob = query_attack();
  stop_fight();
  stop_hunter( 1 );
  ob->stop_fight();
  ob->stop_hunter( 1 );
  return 0;
}

