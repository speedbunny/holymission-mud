inherit "/room/room";

#include "/players/morningsir/defs.h"

reset(arg) {
  if(!arg) {

  set_light(1);
  short_desc="In the village.";
  long_desc=
   "You are walking in one of the village streets. There are busy people around\n" +
   "walking back and forth. Other people are lying on the pavement taking a nap\n" +
   "while beggars sit on the road and gaze at you. The main street goes from west\n" +
   "to the east further into the village. You can see houses of the village and\n" +
   "there is also a sound of marketplace coming from the east.\n";

  dest_dir=({ PATHR + "vil23.c", "west",
              PATHR + "vil25.c", "east"
             });

  items=({ "village", "The village is alive, people move and talk on the streets.",
           "houses", "The houses are made of wood and they look old.",
           "citizens", "The citizens of the village are rushing in the streets.",
           "streets", "There are people rushing in the streets, though they look a bit narrow."
          });

  smell="You feel the typical smell of horses, cows and other cattle.";

  }
  replace_program("room/room");
}
