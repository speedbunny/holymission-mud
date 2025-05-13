#include "../defs.h"

inherit "room/room";

void reset( int arg ) {
  ::reset( arg );

  if( arg ) return;
  set_light( 1 );
  short_desc = "A valley between the last two dark hills in a dark land.";
  long_desc = "You walk in the valley between the last two hills of these "
    + "dark lands. The grey rocky ground is scattered with small sharp "
    + "purple-black stones. The road runs south and northwest up the slopes "
    + "of the two neighbouring hills. A small path runs southwest directly "
    + "to the top of the hill. Further north you see a solitary tower.\n";
  dest_dir = ({
    ROOM_DIR + "darkld10", "northwest",
    ROOM_DIR + "darkld07", "south",
    ROOM_DIR + "darkld08", "southeast",
  });
  items=({ 
    "valley", "The darkness of the hills surrounding it feels threatening",
    "hills", "Hills covered with dark grey sand and dark brown heather "
      + "shrubs border this valley to the southeast and northwest",
    "road", 
      "It looks like a normal dirt road through what used to be a village",
    "ground", "The ground you walk on is solid rock",
    "stones", "These irregular stones are sharp as knives and make it very "
      + "hard to walk. You're sure you don't want to fall down here. As it "
      + "is, you'll probably have to have you boots fixed anyway",
    "tower", "Just off the hills a black tower looms. You notice a cloud "
      + "of tiny spots circling around its spire",
    "cloud", "You are too far away to see any details",
  });
}
