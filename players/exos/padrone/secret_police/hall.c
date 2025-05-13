/* 971011, Uglymouth: Recoded to use /room/doorroom.c now.
 */
#include <doorroom.h>

inherit DOOR_ROOM;

void reset( int arg ) {
  ::reset( arg );
  set_light(1);
  short_desc = "Short Hall";
  long_desc = "You stand in a small hall behind the shop. "
    + "Doors stand at the cardinal directions, and a plaque on the "
    + "wall reads:\n"
    + "'The Service shall stand now and forever to protect and serve.'\n";
  dest_dir = 	({
    "players/padrone/secret_police/office", "north",
    "players/padrone/secret_police/backroom", "south",
    "players/padrone/secret_police/sleeping_room", "east",
    "players/padrone/secret_police/interrogation_room", "west",
  });
  items = ({
    "doors", "Standard wooden doors except fot an iron door to the west",
    "door", "Try iron door instead..",
    "iron door", "dummy door description",
  });
  property = ({ "no_clean_up" });

  set_door( "iron door" );
  set_door_desc( "iron door",
    "An iron door with an iron lock, leading to an isolated room. "
    + "There is a sign saying \"KEEP OUT!\" on this door.\n" );
  set_door_direction( "iron door", "west" );
  set_lock_status( "iron door", DOOR_LOCKED );
  set_door_key( "iron door", "interrogation" );
  set_door_reset( "iron door", ({
    "set_door_status", DOOR_CLOSED,
    "set_lock_status", DOOR_LOCKED,
  }) );
  set_door_reset_msg( "iron door",
    "A suspicious looking man wearing sunglasses comes in, locks the "
    + "iron door and leaves in a hurry.\n" );
  set_other_door( "iron door" );
  replace_program( DOOR_ROOM );
}

