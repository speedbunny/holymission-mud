/* 971031, Uglymouth: recoded to use /room/doorroom.c now.
 */
#include <doorroom.h>

inherit DOOR_ROOM;

void reset( int arg ) {
  set_light(1);
  short_desc = "Corridor of cells";
  long_desc = "You are standing at a narrow corridor that leads to the "
    + "cell rooms of the Shire shiriff station. Lit torchs line "
    + "the walls of the corridor and the flickering flames cast "
    + "dancing shadows on the walls. A celldoor leads west.\n";
  dest_dir = ({
    "/players/colossus/mearth/shire/quest/hall12", "east",
  });
  hidden_dir = ({
    "/players/colossus/mearth/shire/quest/hall10", "west",
  });
  items = ({
    "torches", "The torches are securely fastened to the walls",
    "walls",
      "The flickering flame of the torch casts long shadows on the walls",
    "shadows",
      "The shadows are cast by the flickering flames of the torches",
    "flames",
      "Bright yellowish-orange flames that cast shadows on the walls",
    "door", "Try to look at celldoor instead",
    "celldoor", "dummy door description",
  });

  ::reset( arg );
  replace_program( DOOR_ROOM );
}
