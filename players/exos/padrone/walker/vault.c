/* vault.c
 * Recode - Exos 961026
 * Uglymouth, 970818: Recoded to use /room/doorroom.c; improved readability.
 */
#include <doorroom.h>

inherit DOOR_ROOM;

void reset( int flag ) {
  clone_list = ({
     1, 1, "pirate", "players/padrone/monsters/friendly_pirate", 0,
    -1, 1, "knife", "players/padrone/obj/knife", 0,
     2, 1, "coins", "obj/money", ({ "set_money", (2+random(10)) }),
  });
  ::reset( flag );
  if( flag ) return;

  set_light( 1 );
  short_desc = "Inside the vault of the walking castle";
  long_desc = "This is a steel vault that probably was intended to be the\n"
    + "treasury of the walking castle. It is empty, however, and\n"
    + "part of the vault has been rebuilt into some kind of cell.\n"
    + "A metal door leads back towards the upper hall of the castle.\n"
    + "A panzer door leads to the cell, and from inside you can hear\n"
    + "angry, snarling noises, along with the sound of clawed feet\n"
    + "walking on steel.\n";
  dest_dir = ({
    "/players/padrone/walker/cell", "north",
    "/players/padrone/walker/upper_hall", "south",
  });
  items = ({
    "door", "The metal door or the panzer door?",
    "metal door", "dummy door description",
    "panzer door", "dummy door description",
  });

  set_door( "metal door" );
  set_door_dependent( "metal door", "/players/padrone/walker/upper_hall" );
  set_door( "panzer door" );
  set_door_desc( "panzer door",
    "This is a two feet thick maximum-security bullet-proof bank-vault "
    + "door.\nThere is a sign on the door, saying \"You have "
    + "been warned.\"" );
  set_door_direction( "panzer door", "north" );
  set_lock_status( "panzer door", DOOR_LOCKED );
  set_door_key( "panzer door", "walkercell" );
  set_door_reset( "panzer door", ({
    "set_door_status", DOOR_CLOSED,
    "set_lock_status", DOOR_LOCKED,
  }) );
  set_door_reset_msg( "panzer door", "The north door slams shut\n" );
  set_other_door( "panzer door" );
  replace_program( DOOR_ROOM );
}

