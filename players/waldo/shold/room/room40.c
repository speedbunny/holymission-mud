#include "/players/waldo/defs.h"
inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if (!arg)
  {
    set_light(1);
    short_desc="Bugbears' sitting room";
    long_desc=
    "In this dirty, vile-smelling chamber, a smoky fire is dying in\n"+
    "a large fireplace, and a kettle holding a foul-smelling stew\n"+
    "simmers over the coals. Three large benches, two chairs, and a\n"+
    "table fill the rest of the room.\n";

    dest_dir=({
    STRONGHOLD+"/room/hall3","west",
    STRONGHOLD+"/room/hall4","east",
             });

    items=({
    "bench","It has a large jug and three wine-stained goblets, two\n"+
            "of which are tipped over. All the goblets are encrusted\n"+
            "with dried wine and dirt.\n",
          });

    }
  }

init()
{
  ::init();
  return 1;
  }
