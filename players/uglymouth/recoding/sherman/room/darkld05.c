#include "../defs.h"

inherit "room/room";

int searched;

void reset( int arg ) {
  object ob;

  ::reset( arg );
  searched = 0;
  if( ob = present( "skeleton of a young girl" ) ) {
    tell_room( this_object(), "A sudden gust of wind blows the bones over "
      + "the edge into the ravine.\n" );
    destruct( ob );
  if( ob = present( "silver necklace" ) ) destruct( ob );
  }
  if( arg ) return;

  set_light( 1 );
  short_desc = "On the top of a dark hill in a dark land.";
  long_desc = "You have arrived at the top of a dark hill. The road ends "
    + "suddenly at the edge of a ravine. The ravine is not very wide, but "
    + "not enough light shines into it to allow you to estimate how deep "
    + "it is. The dark brown heather grows up to your knees and because of "
    + "the little more sun reaching this hill top, the shrubs grow very "
    + "densely here.\n";
  dest_dir = ({
    ROOM_DIR + "darkld04", "southeast",
  });
  items=({ 
    "top", "The view you have here at the top makes you realise that this "
      + "must once have been a beautiful country",
    "hill", "The first in a chain of low, dark hills. There are more hills "
      + "to the east. Far east you see the spire of a tower",
    "road", "It looks like a normal dirt road. It stops at the ravine",
    "ravine", "It looks very rough edged, like someone split the hill with "
      + "a huge axe. To satiate your curiousity, you toss a small pebble "
      + "over the egde to listen how long it takes to reach the bottom. "
      + "This proves to be not very long, but chances of surviving a fall "
      + "to the bottom are small nevertheless. The ravine prevents movement "
      + "to the north and west",
    "heather", "The shrubs reach out for every last ray of sunlight they "
      + "can get. The shrubs grow too densely to walk through",
    "shrubs", "The shrubs reach out for every last ray of sunlight they "
      + "can get. The shrubs grow too densely to walk through",
  });
}

void init() {
  ::init();
  add_action( "do_search", "search" );
}

int do_search( string str ) {
  if( str != "heather" && str != "shrubs" ) {
    notify_fail( "You find nothing of interest.\n" );
    return 0;
  }
  if( searched || random( 3 ) ) {
    say( sprintf( "%s is busy with a hopeless attempt to move through "
      + "the shrubs.\n", TPSHORTN ), TP );
    notify_fail( "You find nothing of interest.\n" );
    return 0;
  }
  move_object( clone_object( ITEM_DIR + "bones" ), this_object() );
  printf( "You have a hard time searching through the shrubs until you "
    + "trip over something that you are sure aren't some loose roots. "
    + "As you pull it out, you see it's the skeleton of a young girl.\n" );
  say( sprintf( "%s has a hard time searching among the shrubs. Suddenly "
    + "%s starts pulling something out from the heather shrubs.\n",
    TPSHORTN, TPPRN ), TP );
  return 1;
}
