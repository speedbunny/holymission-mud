inherit "/room/room";

#include "/players/morningsir/defs.h"

reset(arg) {
  if(!arg) {

  set_light(1);
  short_desc="In the village.";
  long_desc=
   "You are walking in one of the village streets. There are busy people around\n" +
   "walking back and forth. Other people are lying on the pavement taking a nap\n" +
   "while beggars sit on the road and gaze at you. The main street goes from here\n" +
   "to the main square which is in the western direction. You can see houses of\n" +
   "the village and there is also a sound of marketplace coming from the northwest.\n";

  dest_dir=({ PATHR + "vil35.c", "northwest",
              PATHR + "vil36.c", "west",
              PATHR + "vil38.c", "southeast"
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
