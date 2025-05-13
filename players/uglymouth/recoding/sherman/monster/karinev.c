#include "../defs.h"

inherit GEN_VAMPIRE;

void reset( int arg ) {
  object ring;

  ::reset(arg);
  if( !present( "night cape", this_object() ) ) {
    transfer( clone_object( ITEM_DIR + "nitecape" ), this_object() );
    init_command( "wear cape" );
  }
  if( !present( "diamond ring" ) ) {
    // no AC, but at least you can wear it...
    ring = clone_object( "/obj/armour" );
    ring->set_name( "diamond ring" );
    ring->set_alias( "ring" );
    ring->set_short( "A diamond ring" );
    ring->set_long( "This ring has been cut from one single diamond. "
      + "It's many facets make it glitter with rainbow colours in even "
      + "the weakest light. You realize that only the diamond dust lost "
      + "with cutting such a treasure could make a man rich.\n" );
    ring->set_type( "ring" );
    ring->set_value( 2001 );
    transfer( ring, this_object() );
    init_command( "wear ring" );
  }
  if( arg ) return;
  
  set_name( "karinev the vampire" );
  set_alias( "karinev" );
  set_short( "Lady Karinev, the vampire countess" );
  set_long( "Lady Karinev, the vampire countess.\n" );
  set_level( 20 );
  set_gender( 2 );
  set_al( -250 );
  set_ac( 15 );
  set_wc( 25 );
}
