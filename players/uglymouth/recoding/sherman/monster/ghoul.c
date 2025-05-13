#include "../defs.h"

inherit "obj/monster";

void reset( int arg ) {
  ::reset(arg);
  if (arg) return;

  set_name( "ghoul" );
  set_short( "A man-hunting ghoul" );
  set_long( "This monster looks like a recently died human, but with very "
    + "distorted facial and limb features. It has double-pointed ears, "
    + "purple goattlike eyes, its bald skull is full of warts and it shows "
    + "a mouth full of razor sharp teeth. Its hands have developed into "
    + "catlike claws. It craves for human flesh to devour.\n" );
  set_level( 5 + random( 4 ) );
  set_race("undead");
  set_al( -250 );
  set_ac( 3 );
  set_aggressive( 1 );
  set_wc( 12 );
// What does this statement do???
//  hands = ({ this_object() });
  set_trapped( 1 );
  add_money( random( 100 ) );
}

void init() {
  ::init();
  add_action( "go_east", "east" );
}

// type_def???
hit( ob ) {
  if( random( 100 ) > 20 ) return;
  tell_object( ob, 
    "The ghoul's icy touch drains all the strength from your muscles.\n" );
  ob->hold( this_object(), random( 10 ) + 1 );
}

int go_east() {
  write( "The ghoul blocks your way, It's desparate for an easy meal...\n" );
  return 1;
}
