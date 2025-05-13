/* 971031, Uglymouth: removed TWO_EXIT and MAKE_DOOR, added replace_program.
 */
#include <doorroom.h>

inherit DOOR_ROOM;

void reset( int arg ) {
  clone_list = ({
    1, 1, "harpy", "/players/airborne/monsters/direharp", 0,
   -1, 1, "templestart", "/obj/thing", ({
      "set_name", "golden key",
      "set_alias", "key",
      "set_alt_name", "templestart",
      "set_short", "A golden key",
      "set_long", "A golden key. You wonder where it fits...\n",
      "set_value", 10,
    }),
  });

  set_light( 1 );
  short_desc = "The doorway to the temple";
  long_desc = "This is the doorway to the temple of the Old Ones. "
    + "A golden door leads north into the temple. Turn back while you "
    + "still can!\n";
  dest_dir = ({
    "/players/airborne/temple/levela/room1", "north",
    "/players/airborne/temple/entrance/stairs1", "down",
  });
  items = ({
    "door", "dummy door description",
  });
  ::reset( arg );

  set_door( "door" );
  set_door_desc( "door", "This door is the same golden color as the "
    + "rest of the temple. It's lock is of the same material" );
  set_door_direction( "door", "north" );
  set_lock_status( "door", DOOR_LOCKED );
  set_door_key( "door", "templestart" );
  set_door_reset( "door", ({
    "set_door_status", DOOR_CLOSED,
    "set_lock_status", DOOR_LOCKED,
  }) );
  set_door_reset_msg( "door", "A harpy angrily shuts the door.\n" );
  set_other_door( "door" );

  replace_program( DOOR_ROOM );
}
