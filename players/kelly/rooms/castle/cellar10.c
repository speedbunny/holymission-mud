/* 970915, Uglymouth: Now using /room/doorroom.c and replace_program().
 */
#include <doorroom.h>

inherit DOOR_ROOM;

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;
  set_light( 0 );
  short_desc = "In the cellar";
  long_desc = "You are in the cellar of the castle. Stairs lead "
    + "down into a dungeon. In both the north wall and the south "
    + "are doors.\n";
  dest_dir = ({
    "players/kelly/rooms/castle/dungeon1", "down",
    "players/kelly/rooms/castle/cellar1", "south",
    "players/kelly/rooms/castle/cellar11", "north",
  });
  items = ({
    "doors", "There's the cellar door in the south wall and "
      + "the metal door in the north wall",
    "cellar door", "dummy door description",
    "metal door", "dummy door description",
  });

  set_door( "metal door" );
  set_door_desc( "metal door",
    "This is a solid looking metal door. It has an iron lock in it" );
  set_door_direction( "metal door", "north" );
  set_lock_status( "metal door", DOOR_LOCKED );
  set_door_key( "metal door", "dungeondoor" );
  set_door_reset( "metal door", ({
    "set_door_status", DOOR_CLOSED,
    "set_lock_status", DOOR_LOCKED,
  }) );
  set_door_reset_msg( "metal door", "CLANG! The metal door slams shut.\n" );
  set_other_door( "metal door" );
  replace_program( DOOR_ROOM );
}
