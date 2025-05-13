/* 971031, Uglymouth: removed FOUR_EXIT and MAKE_DOORS, added replace_program
 */
#include <doorroom.h>

inherit DOOR_ROOM;

void reset( int arg ) {
  clone_list = ({
    1, 1, "priest", "/players/airborne/monsters/priest", 0,
   -1, 1, "altardoor", "/obj/thing", ({
      "set_name", "blackened steel key",
      "set_alias", "key",
      "set_alt_name", "altardoor",
      "set_short", "A blackened steel key",
      "set_long", "This is a blackened steel key. You wonder where it fits.\n",
      "set_value", 10,
    }),
  });

  set_light( 0 );
  short_desc = "The priest room";
  long_desc = "This room is barred by a big, blackened steel door to the "
    + "north. What could be on the other side?\n";
  dest_dir = ({
    "/players/airborne/temple/levelb/room10", "north",
    "/players/airborne/temple/levelb/room9", "east",
    "/players/airborne/temple/levelb/room5", "south",
    "/players/airborne/temple/levelb/room7", "west",
  });
  items = ({
    "door", "dummy door description",
  });
  ::reset( arg );

  set_door( "door" );
  set_door_desc( "door", "This is a solid blackened steel door" );
  set_door_direction( "door", "north" );
  set_lock_status( "door", DOOR_LOCKED );
  set_door_key( "door", "altardoor" );
  set_door_reset( "door", ({
    "set_door_status", DOOR_CLOSED,
    "set_lock_status", DOOR_LOCKED,
  }) );
  set_door_reset_msg( "door",
    "A priest shuts and locks the blackened steel door.\n" );
  set_other_door( "door" );

  replace_program( DOOR_ROOM );
}
