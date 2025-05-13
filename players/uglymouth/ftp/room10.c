/* 971031, Uglymouth: recoded to use /room/doorroom.c now.
 */
#include <doorroom.h>

inherit DOOR_ROOM;

void reset( int arg ) {
  set_light( 0 );
  short_desc = "The hallway";
  long_desc = "This is the begining of a hallway. There is a door to the "
    + "south and the hall continues to the north.\n";
  dest_dir = ({
    "/players/airborne/temple/levelb/throne", "north",
    "/players/airborne/temple/levelb/room8", "south",
  });
  items = ({
    "door", "dummy door description",
  });
  ::reset( arg );
  replace_program( DOOR_ROOM );
}
