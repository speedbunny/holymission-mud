/* 971031, Uglymouth: recoded to use /room/doorroom.c now.
 */
#include <doorroom.h>
#include "/players/trout/defs.h"

inherit DOOR_ROOM;

void reset( int arg ) {
  set_light( 1 );
  short_desc = "Usegi's Gambling Hall";
  long_desc = "You are standing in a dim room, filled with smoke. People "
    + "fill the room, crowded around various tables. Each table has a "
    + "different game of chance on it. A band plays live music from the "
    + "southeast corner. There's a door to the east.\n";
  dest_dir = ({
    ZZ+"/alley8", "leave",
    ZZ+"/gamb2", "east",
  });
  items = ({
    "tables", "You see a poker table and a blackjack table near you",
    "band", "An oriental jazz band. Imagine that!",
    "door", "dummy door description",
  });
  ::reset( arg );

  set_door( "door" );
  set_door_desc( "door",
    "This heavy iron door says 'employees only' on it" );
  set_door_direction( "door", "east" );
  set_lock_status( "door", DOOR_LOCKED );
  set_door_key( "door", "gambling_hall" );
  set_door_reset( "door", ({
    "set_door_status", DOOR_CLOSED,
    "set_lock_status", DOOR_LOCKED,
  }) );
  set_door_reset_msg( "door", "The door swings shut.\n" );
  set_other_door( "door" );

  replace_program( DOOR_ROOM );
}
