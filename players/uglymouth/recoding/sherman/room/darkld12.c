#include "../defs.h"

inherit "room/room";

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;

  set_light( 1 );
  short_desc = "On the north slope of a dark hill in a dark land.";
  long_desc = "You walk along the north slope of the last dark hill. "
    + "The path you followed ends at the ruins of a small farm. You can "    
    + "follow it back south. Of the main building of the farm not a single "
    + "stone has been left on another. One of the wooden outhouses seems "
    + "to partly have survived the destruction. Further north a dark and "
    + "impenetrable forest forms the force that seals off these lands.\n";
  dest_dir = ({
    ROOM_DIR + "darkld10", "south",
  });
  items=({ 
    "slope", "The bare rock of the slope doesn't leave much room for plants "
      + "to grow on",
    "hill", "The last in a chain of low, dark hills. You feel like this "
      + "might be the end of the world",
    "path", "A winding strip of bare rock among the vegetation",
    "ruins", "You wonder what force could have brought this about. Not a "
      + "single piece of stone was has survived the catastrophe",
    "farm", "You wonder what force could have brought this about. Not a "
      + "single piece of stone was has survived the catastrophe",
    "outhouse", "About half of it has collapsed. You think that you could "
    + "enter the remaining part through an opening in the planks",
  });
}

void init() {
  ::init();
  add_action( "do_enter", "enter" );
}

int do_enter( string str ) {
  int i;

  if( str != "outhouse" && str != "opening" ) {
    notify_fail( "What do you want to enter?\n" );
    return 0;
  }
  TP->move_player( "into the outhouse through the opening in the planks#"
    + ROOM_DIR + "outhouse" );
  if( !present( "bat" ) ) {
    for( i=0; i<random(5)+1; i++ ) 
      move_object( clone_object( MON_DIR + "vampbat" ), this_object() );
    tell_room( this_object(), sprintf( "Just after %s left, some bats swoop down from "
      + "the air, angry at people entering their territory.\n", TPSHORTN ) );
  }
  return 1;
}

