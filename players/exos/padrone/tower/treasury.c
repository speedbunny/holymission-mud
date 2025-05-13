/* 930223, Ethereal Cashimor: File changed to use room/room. Also changed
 *   to have our way of preventing teleport.
 * 970913, Uglymouth: using /room/doorroom.c now and updated old code.
 */
#include <doorroom.h>

inherit DOOR_ROOM;

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;
  set_light(1);
  short_desc = "The treasury";
  long_desc = "You are standing just outside the great door leading to the "
    + "vault where the treasure is stored. You notice that the floor "
    + "has been engraved with anti-teleport runes.\n";
  dest_dir = ({
    "players/padrone/tower/rambo_room", "south",
  });
  hidden_dir = ({
    "players/padrone/tower/vault", "north",
  });
  smell = "The smell of gold is even stronger here!";
  items = ({
    "vault", "Probably behind the door",
    "floor", "It looks smooth, except for the runes",
    "runes", "They probably are very effective",
    "door", "dummy door description",
  });
  property = "no_teleport";

  set_door( "door" );
  set_door_desc( "door",
    "This is a door made of steel and mithril, several inches thick. "
    + "You notice a maximum-security lock on it" );
  set_door_direction( "door", "north" );
  set_lock_status( "door", DOOR_LOCKED );
  set_door_key( "door", "vaultdoor" );
  set_door_reset( "door", ({
    "set_door_status", DOOR_CLOSED,
    "set_lock_status", DOOR_LOCKED,
  }) );
  set_door_reset_msg( "door",
    "Slowly but irrevocably the vault door slides shut.\n" );
  set_other_door( "door" );
  replace_program( DOOR_ROOM );
}
