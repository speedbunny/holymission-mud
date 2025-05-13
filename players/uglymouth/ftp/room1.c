/* 971031, Uglymouth: Recoded to use /room/doorroom.c now.
 */
#include <doorroom.h>

inherit DOOR_ROOM;

void reset( int arg ) {
  set_light( 0 );
  short_desc = "The archway to the temple";
  long_desc = "This is the archway to the temple itself. "
    + "The temporary location of the temple's speak-easy it to the west. "
    + "You hear noises coming from the north and east. A door made of some "
    + "golden material leads south.\n";
  dest_dir = ({
    "/players/airborne/temple/levela/room3", "north",
    "/players/airborne/temple/levela/room2", "east",
    "/players/airborne/temple/tavern", "west",
    "/players/airborne/temple/levela/stairs2", "south",
  });
  items = ({
    "archway", "A golden archway to the temple of the Old Ones",
    "door", "dummy door description",
  });
  ::reset( arg );
  replace_program( DOOR_ROOM );
}
