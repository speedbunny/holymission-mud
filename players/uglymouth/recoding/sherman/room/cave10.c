#include "../defs.h"

inherit "room/room";

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;

  set_light( -1 );
  short_desc = "At the dead end in a very dark cave under a dark hill";
  long_desc = "You have arrived at the dead end of a very dark cave in "
    + "a dark hill. It looks like this is a natural cave, eroded into "
    + "the hard rock a long time ago. The northeast wall however, seems a "
    + "bit too smooth to be natural erosion.\n";
  dest_dir = ({
    ROOM_DIR + "cave09", "southwest",
  });
  items=({ 
    "cave", "Just a natural cave. It's fairly dry",
    "hill", "It's oppressing presence is all around you",
    "rock", "Dark grey, hard rock",
    "wall", 
      "It looks like natural rock, but you're not covinced it's natural",
  });
}

void init() {
  ::init();
  add_action( "do_search", "search" );
  add_action( "do_touch", "touch" );
}

int do_search( string str ) {
  if( str != "wall" && str != "northeast wall" && str != "rock" &&
      str != "text" )
    return 0;
  if( str != "text" ) {
    printf( "As your fingers touch the rock, you discover the outlines of "
      + "a secret door in the northeast wall. Along the edge you feel some "
      + "text engraved in the rock. However, it's so vague that you "
      + "couldn't read it even in broad day light.\n" );
    return 1;
  }
  printf( "After careful examination your finger tips tell you: \"Only a "
    + "vampire who touches the secret door can pass it\".\n" );
  return 1;
}

int do_touch( string str ) {
  string what;

  if( !str ) return 0;
  if( sscanf( str, "%s with rib", what ) != 1 ) {
    notify_fail( "What is it that you wish to touch, and with what do you "
      + "wish to touch it?\n" );
    return 0;
  }
  if( what != "secret door" && what != "door" && what != "northeast wall" &&
      what != "wall" ) {
    printf( "You touch the %s with the rib, although you don't see the use "
      + "of it.\n", what );
    return 1;
  }
  if( !present( "vampire rib", TP ) ) {
    notify_fail( "A chilling shock shoots through your body as you touch "
      + "the " + what + ".\n" );
    return 0;
  }
  printf( "As you touch the secret door with the rib, you feel yourself "
    + "become ethereal, being sucked through the secret door and solidify "
    + "again at the other side.\n" );
  say( sprintf( "%s seems to dissolve into thin air!\n",
    this_player()->query_short_name() ), this_player() );
  TP->move_player( "X#" + ROOM_DIR + "vtower07" );
  return 1;
}

