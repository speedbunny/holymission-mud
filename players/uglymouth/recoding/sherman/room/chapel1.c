#include "../defs.h"

inherit "room/room";

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;

  set_light( 1 );
  short_desc = "Inside the chapel belonging the cemetary.";
  long_desc = "You have entered the chapel of the cemetary. There is a "
    + "small altar against the back wall. The windows have been smashed "
    + "and there no longer is a door in the doorway. Still this feels like "
    + "a place of peace. Many people got their last blessing "
    + "here before being carried to their final resting places.\n";
  dest_dir = ({
    ROOM_DIR + "cemetry6","west",
    ROOM_DIR + "chapel2", "south",
  });
  items=({
    "chapel", "A chapel dedicated to the last rituals of life",
    "altar", "This center of worship has miraculously survived the "
      + "destruction of this place. It's consists of a white stone "
      + "table covered with a pitch black cloth",
    "table", "It is of massive stone, with a thick layer of dust",
    "cloth", 
      "It's woven of thick strands of cotton and covered with a lot of dust",
    "windows", 
      "They're small square windows with a few shards of broken glass in it",
    "doorway", 
      "It's little more than a rectangular opening in the west wall",
  });
  property = "no_fight";
}

void init() {
  ::init();
  if( (string)this_player()->query_race() == "undead" )
    this_player()->move_player( "west, fleeing from holy ground#"
      + ROOM_DIR + "cemetry6" );
}

