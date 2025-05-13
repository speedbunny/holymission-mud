/* walker/cell.c
 * Recode - Exos 961024
 * Uglymouth, 970818: Recoded to use /room/doorroom.c; improved readability.
 */
#include "walker.h"
#include <doorroom.h>

inherit DOOR_ROOM;

void reset( int flag ) {
  clone_list = ({
     1, 1, "chaosdemon", "/players/padrone/monsters/chaos_demon", 0,
    -1, 1, "chaosblade", "/players/padrone/obj/chaos_blade", 0,
    -1, 1, "chest", "obj/chest", 0,
  });
  ::reset(flag);
  if( flag ) return;

  set_light( 0 );
  short_desc = "In a dark Cell inside the walking castle";
  long_desc =
    "This is an air-tight steel room inside the walking castle.\n"
    + "There are no openings, except for a heavy panzer door to the south.\n"
    + "The floor has been engraved with anti-teleport runes, and on the\n"
    + "walls you see spells of imprisonment softly glowing in the dim "
    + "light.\n";
  dest_dir = ({  
    "/players/padrone/walker/vault", "south",
  });
  items = ({
    "door", "You mean the 'panzer door'...?",
    "panzer door", "dummy door description",
  });
  property = "no_teleport";

  set_door( "panzer door" );
  set_door_dependent( "panzer door", "/players/padrone/walker/vault" );
  replace_program( DOOR_ROOM );
}

