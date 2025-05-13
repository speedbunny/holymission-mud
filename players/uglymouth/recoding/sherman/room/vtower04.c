#include "../defs.h"

inherit "room/room";

void reset( int arg ) {
  clone_list = ({
    1, 1, "boris the vampire", MON_DIR + "boris", 0,
    2, 1, "marushka the vampire", MON_DIR + "marushka", 0,
  });
  ::reset( arg );
  if( arg ) return;
  set_light( 1 );
  short_desc = "On the second floor of a black tower.";
  long_desc = "You have arrived at the second floor of the black tower. This "
    + "is the main hall of the tower. There is a big, pentagram-shaped "
    + "table in the centre surrounded by soft chairs. The table is full "
    + "with crystal glasses containing a red fluid. Tapestries line the "
    + "outer circular wall, blinding all windows. A flight of stairs "
    + "spirals upward and downward.\n";
  dest_dir = ({
    ROOM_DIR + "vtower05", "up",
    ROOM_DIR + "vtower03", "down",
  });
  items=({
    "tower", "You are inside it",
    "hall", "The main hall is where the lord entertains his guests",
    "table", "Made of ebony, its shape mocks every round table ever made",
    "chairs", 
      "Made of chestnut wood. They have high carved backs and sotf cushions",
    "glasses", "It's the finest crystal you have seen in a long time",
    "fluid", "You dip your finger and taste it. It's blood!",
    "tapestries", "Scenes of bloody battles are all around you",
    "windows", "Daylight has carefully been banned from this room",
    "stairs", "A wide, spiralling flight of stone stairs",
  });
}

int move( string str ) {
  object vamp;

  if( !( vamp = present( "vampire", this_object() ) ) )
    return ::move( str );
  if( !( 45 - (int)this_player()->query_dex() ) ) {
    printf( "You manage to swiftly duck past the vampire.\n" );
    return ::move( str );
  }
  printf( "%s moves in your path, preventing you from leaving.\n",
    vamp->short() );
  say( sprintf( "%s prevents %s from leaving.\n", vamp->short(),
    this_player()->query_short_name() ), this_player() );
  return 1;
}

