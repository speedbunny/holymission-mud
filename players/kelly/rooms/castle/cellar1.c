/* 970915, Uglymouth: getting rid of ONE_EXIT and MAKE_DOOR macro's
 *   Now using /room/doorroom.c and replace_program().
 */
#include <doorroom.h>

inherit DOOR_ROOM;

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;
  set_light( 0 );
  short_desc = "In the cellar";
  long_desc = "You are in the cellar of the castle. "
    + "There is a door in the north wall.\n";
  dest_dir = ({
    "players/kelly/rooms/castle/cellar", "east",
    "players/kelly/rooms/castle/cellar10", "north",
  });
  items = ({
    "door", "Try 'cellar door' instead",
    "cellar door", "dummy door description",
  });

  set_door( "cellar door" );
  set_door_desc( "cellar door", "This is a solid looking metal door. "
    + "You notice an iron lock on it" );
  set_door_direction( "cellar door", "north" );
  set_lock_status( "cellar door", DOOR_LOCKED );
  set_door_key( "cellar door", "dungeondoor" );
  set_door_reset( "cellar door", ({
    "set_door_status", DOOR_CLOSED,
    "set_lock_status", DOOR_LOCKED,
  }) );
  set_door_reset_msg( "cellar door",
    "BANG! The cellar door slams shut.\n" );
  set_other_door( "cellar door" );
  replace_program( DOOR_ROOM );
}
