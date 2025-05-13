/*  This is the first Bedchamber in the East Wing  
 * 971031, Uglymouth: recoded to use /room/doorroom.c now.
 */
#include <doorroom.h>
#include "/players/tamina/defs.h"

inherit DOOR_ROOM;

void reset( int arg ) {
  clone_list = ({
    1, 1, "bed", COBJ + "bed", 0,
  });
  set_light(1);
  short_desc = "Bed Chamber";
  long_desc = "This room is surprisingly clean, compared to the dust and "
    + "dirt in the corridor outside.  However, on the open window, you can "
    + "see signs of a lack of cleaning.  A cool breeze flutters in through "
    + "the small gap in the wall, airing the room pleasantly.  There is a "
    + "four-poster bed against the wall to the left, with a screen pulled "
    + "round it.  There is also a chest at the foot of the bed.\n";
  items = ({
    "screen", "Perhaps if you pulled it aside, you would get a better "
      + "view of the bed",
    "window", "The open window shows a large expanse of green rolling "
      + "hills, with the occasional copse of beech or alder",
    "bedroom", "It is a much more cleaner room than the others in this "
      + "castle.  You would think that someone was living here "
      + "at the moment..",
    "chest", "It seems to be an old, worthless chest, which you don't "
      + "want to waste your time over",
    "door", "dummy door description",
  });
  no_obvious_msg = "";
  ::reset( arg );
  replace_program( DOOR_ROOM );
}

