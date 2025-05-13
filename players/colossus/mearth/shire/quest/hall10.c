/* 971031, Uglymouth: recoded to use /room/doorroom.c now.
 */
#include <doorroom.h>

inherit DOOR_ROOM;

void reset(int arg){
  set_light(1);
  short_desc = "Stairs leading up";
  long_desc = "You are standing at the bottom of a flight of stairs leading "
    + "up to the ground level of the shiriff station. Lying to your "
    + "east is a small celldoor that leads to the cells.\n";
  dest_dir = ({
    "/players/colossus/mearth/shire/quest/hall5", "stairs",
  });
  hidden_dir = ({
    "/players/colossus/mearth/shire/quest/hall11", "east",
  });
  items = ({
    "stairs", "A flight of stone stairs leading up",
    "door", "Try look at celldoor instead",
    "celldoor", "dummy door description",
  });
  ::reset( arg );

  set_door( "celldoor" );
  set_door_desc( "celldoor",
    "A small but sturdy celldoor with a metal lock" );
  set_door_direction( "celldoor", "east" );
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
