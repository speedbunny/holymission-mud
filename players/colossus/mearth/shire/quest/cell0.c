/* 971031, Uglymouth: recoded to use /room/doorroom.c now.
 */
#include <doorroom.h>

inherit DOOR_ROOM;

void reset( int arg ) {
  set_light( 1 );
  short_desc = "Prison cell";
  long_desc = "The cell contains a single cot attached to the wall by "
    + "two chains and a long hinge that allows it to be folded up "
    + "against the wall. A small hole has been cut through the stone "
    + "floor and is located at the inner left corner. The celldoor is "
    + "built into the north wall.\n";
  hidden_dir = ({
    "/players/colossus/mearth/shire/quest/hall12", "north",
  });
  items = ({
    "cot", "The cot looks fairly comfortable",
    "walls", "The stone walls are thick and unpenetrable",
    "chains", "The chains are the main support for the cot",
    "hinge", "The hinge controls the chains that support the bed",
    "hole", "The small hole on the floor serves as the sanitary facility",
    "door", "Try celldoor..",
    "celldoor", "dummy door description",
  });

  ::reset( arg );
  replace_program( DOOR_ROOM );
}

