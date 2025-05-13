inherit "/room/room";

#include "/players/morningsir/defs.h"

reset(arg) {
  if(!arg) {

  set_light(1);
  short_desc="Near the forest.";
  long_desc=
   "You are walking on the road which enters the forest to the west and\n" +
   "continues northeast to the village. The forest doesn't seem too dense\n" +
   "to enter. You can see houses of the village and citizens walking on\n" +
   "the streets.\n";

  dest_dir=({ PATHR + "vil21.c", "west",
              PATHR + "vil23.c", "northeast"
             });

  items=({ "forest", "The forest seems to be bright and full of animals.",
           "trees", "The trees are mostly pines.",
           "road", "It's a forest road, quite dirty, but dry after all.",
           "houses", "The houses are made of wood and they look old.",
           "citizens", "The citizens of the village are rushing in the streets.",
           "streets", "You cannot see that far."
          });

  smell="You feel the pine aroma in the air.";

  }
  replace_program("room/room");
}
