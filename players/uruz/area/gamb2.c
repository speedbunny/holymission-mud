/* 971031, Uglymouth: recoded to use /room/doorroom.c now.
 */
#include <doorroom.h>
#include "/players/trout/defs.h"

inherit DOOR_ROOM;

void reset( int arg ) {
  clone_list = ({
    1, 2, "wyng", MM+"/wyng", 0,
   -1, 1, "opium", YY+"/obj/opium", 0,
  });

  set_light( 1 );
  short_desc = "Back Room";
  long_desc = "You have entered a small room. A single light hangs over "
    + "a large table, barely lighting the whole thing up. On the table is "
    + "a enough opium to never stay sober again. Several balances and trays "
    + "occupy the table, ready to divide the opium into kilograms. You "
    + "get the feeling you weren't supposed to see this. On the wall you "
    + "spot the symbol of the Wyng Kong. There's a door to the west.\n";
  dest_dir = ({
    ZZ+"/gamb1", "west",
  });
  items = ({
    "balance", "Used to measure out the opium by wieght",
    "tray", "Traces of opium are visible in it",
    "table", "A large wooden table with various measuring tools on it",
    "light", "A single lamp hangs from the ceiling",
    "symbol", "A symbol of a white peacock fighting a red dragon",
    "door", "dummy door description",
  });

  ::reset( arg );
  replace_program( DOOR_ROOM );
}
