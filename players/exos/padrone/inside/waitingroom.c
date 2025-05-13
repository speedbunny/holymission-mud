/* Uglymouth, 970724: Recoded room to use current code standards.
*/
#include <doorroom.h>
// #include "/players/uglymouth/recoding/doors/doorroom.h"

inherit DOOR_ROOM;

void reset( int arg ) {
  ::reset(arg);
  set_light( 1 );
  short_desc = "Waiting room";
  long_desc =
    "This is the waiting room, where people who want help or advice\n" +
    "from the mighty Wizard sit and wait until they are admitted\n" +
    "to the consultation room to the east.\n" +
    "Through the door to the west you can see the main hall,\n" +
    "but there is also a small door to the south.\n" +
    "There is a sign on that door saying 'PRIVATE!'.\n";
  dest_dir = ({
    "players/padrone/inside/main_hall", "west",
    "players/padrone/inside/cons", "east",
  });
  hidden_dir = ({
    "players/padrone/tower/tower1", "south",
  }); 
  items = ({
    "door", "Dummy description for door",
  });

  set_door( "door" );
  set_door_desc( "door",
    "It is a thick and solid door with a crystal lock, "
    + "and it has a sign saying 'PRIVATE'" );
  set_door_direction( "door", "south" );
  set_lock_status( "door", DOOR_LOCKED );
  set_door_key( "door", "towerdoorkey" );
  set_door_reset( "door", ({
    "set_door_status", DOOR_CLOSED,
    "set_lock_status", DOOR_LOCKED,
  }) );
  set_door_reset_msg( "door",
    "A magic spell on the door closes and locks it again.\n" );
  set_other_door( "door" );

  replace_program( DOOR_ROOM );
}
