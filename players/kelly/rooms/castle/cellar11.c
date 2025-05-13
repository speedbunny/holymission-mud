/* 970915, Uglymouth: now using /room/doorroom.c and replace_program().
 */
#include <doorroom.h>

inherit DOOR_ROOM;
 
void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;
  set_light( 1 );
  short_desc = "In the cellar";
  long_desc = "You're in the cellar of the castle. Stairs lead "
    + "upwards. There's a metal door in the south wall.\n";
  dest_dir = ({
    "players/kelly/rooms/castle/castle_yard", "up",
    "players/kelly/rooms/castle/cellar10", "south",
  });
  items = ({
    "metal door", "dummy door description",
  });
  replace_program( DOOR_ROOM );
}
