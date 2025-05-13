/* 971031, Uglymouth: recoded to use /room/doorroom.c now.
 */
#include <doorroom.h>

inherit DOOR_ROOM;

void reset( int arg ) {
  set_light( 1 );
  short_desc = "Corridor of cells";
  long_desc = "You are standing at a narrow corridor that leads to the "
    + "cell rooms of the Shire shiriff station. Lit torchs line "
    + "the walls of the corridor and the flickering flames cast "
    + "dancing shadows on the walls. A celldoor is in the south wall.\n";
  dest_dir = ({
    "/players/colossus/mearth/shire/quest/hall15", "east",
    "/players/colossus/mearth/shire/quest/hall13", "west",
  });
  hidden_dir = ({
    "/players/colossus/mearth/shire/quest/cell2", "south",
  });
  items = ({
    "torches", "The torches are securely fastened to the walls",
    "walls",
      "The flickering flame of the torch casts long shadows on the walls",
    "shadows",
      "The shadows are cast by the flickering flames of the torches",
    "flames",
      "Bright yellowish-orange flames that cast shadows on the walls",
    "door", "Use celldoor instead",
    "celldoor", "dummy door description",
  });
  ::reset( arg );

  set_door( "celldoor" );
  set_door_desc( "celldoor",
    "The celldoor is solidly built and has a metal lock" );
  set_door_direction( "celldoor", "south" );
  set_lock_status( "celldoor", DOOR_LOCKED );
  set_door_key( "celldoor", "iron" );
  set_door_reset( "celldoor", ({
    "set_door_status", DOOR_CLOSED,
    "set_lock_status", DOOR_LOCKED,
  }) );
  set_door_reset_msg( "celldoor", "The celldoor swings shut.\n" );
  set_other_door( "celldoor" );

  replace_program( DOOR_ROOM );
}
