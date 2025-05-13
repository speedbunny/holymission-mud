inherit "/room/room";

#include "/players/morningsir/defs.h"

reset(arg) {
  if(!arg) {

  set_light(1);
  short_desc="In the village.";
  long_desc=
   "You are walking in one of the village streets. There are busy people around\n" +
   "walking back and forth. Other people are lying on the pavement taking a nap\n" +
   "while beggars sit on the road and gaze at you. You can hear voices coming\n" +
   "probably from the village's main street which is to the west and south from\n" +
   "here. You can see houses of the village and there is also a sound of\n" +
   "marketplace coming from the west.\n";

  dest_dir=({ PATHR + "vil32.c", "northwest",
              PATHR + "vil33.c", "west",
              PATHR + "vil34.c", "southwest",
              PATHR + "vil36.c", "south",
              PATHR + "vil37.c", "southeast"
             });

  items=({ "village", "The village is alive, people move and talk on the streets.",
           "houses", "The houses are made of wood and they look old.",
           "citizens", "The citizens of the village are rushing in the streets.",
           "streets", "There are people rushing in the streets, though they look a bit narrow."
          });

  smell="You feel various aromas coming from the marketplace.";

  }
  replace_program("room/room");
}
