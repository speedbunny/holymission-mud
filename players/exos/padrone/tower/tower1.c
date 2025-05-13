/* Uglymouth, 970724: Recoded to use current standard code.
#include "/players/uglymouth/recoding/doors/doorroom.h"
 */
#include <doorroom.h>
#include "../config.h"

inherit DOOR_ROOM;

void reset( int arg ) {
  set_light( 1 );
  short_desc = "Inside Padrone's private tower";
  long_desc = "You are at the bottom of Padrone's private tower.\n" +
    "This is a circular room with walls and floor made of stone.\n" +
    "It is dark and a bit damp, and you can see a stone staircase\n" +
    "winding its way up through the darkness. Another staircase\n" +
    "leads down into a dark hole in the floor. A door leads north.\n";
 dest_dir = ({
    "players/padrone/tower/tower2", "up",
//  "players/padrone/my_void", "down",
  });
  hidden_dir = ({
    "players/padrone/inside/waitingroom", "north",
  });
  items = ({
    "door", "Dummy door description",
  });
  ::reset( arg );

  set_door( "door" );
  set_door_dependent( "door", "/players/padrone/inside/waitingroom" );

  replace_program( DOOR_ROOM );
}
