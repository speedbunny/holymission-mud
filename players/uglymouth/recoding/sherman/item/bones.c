#include "../defs.h"

inherit "obj/thing";

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;

  set_name( "skeleton of a young girl" );
  set_alias( "skeleton" );
  set_short( "A skeleton of a young girl" );
  set_long( "This is the skeleton of a young girl. It seems to be intact, "
    + "and although the head lies at a strange angle sidewards, the neck "
    + "is not broken. Close examination reveals two small pinpointdents "
    + "in the neck vertebrae. As you stare at them, you hear a voice in "
    + "your head saying: Please help me find rest.\n" );
  set_weight( 20 );
  set_value( 0 );
}

void init() {
  ::init();
  add_action( "do_bury", "bury" );
}

int do_bury( string str ) {
  object cross;
  int i;

  if( !id( str ) ) return 0;
  cross = clone_object( ITEM_DIR + "cross" );
  if( i = transfer( cross, this_player() ) )
    move_object( cross, environment( this_player() ) );
  this_player()->add_alignment( 25 );
  printf( "As you dig a grave for the bones of the girl, you find a "
    + "necklace in the sand. %sAs you bury the bones, a voice in your head "
    + "says: Thank you for putting me to rest at last...", 
    i ? "As you pick it up, it slips out of your hands." : "" );
  say( sprintf( "%s buries the bones of a young girl.\n",
    this_player()->query_short_name() ), this_player() );
  return 1;
}

