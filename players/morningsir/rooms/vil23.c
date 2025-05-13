inherit "/room/room";

#include "/players/morningsir/defs.h"

reset(arg) {
 if(arg) return;

  set_light(1);
  short_desc="On the road.";
  long_desc=
   "You are walking on the road which enters the forest to the southwest and\n" +
   "continues in eastern direction further into the village. You can see houses\n" +
   "of the village and citizens walking on the streets. There is a sign hanging\n" +
   "on a column.\n";

  dest_dir=({ PATHR + "vil22.c", "southwest",
              PATHR + "vil24.c", "east"
             });

  items=({ "forest", "The forest seems to be bright and full of animals.",
           "road", "The road is quite dirty, but dry after all.",
           "houses", "The houses are made of wood and they look old.",
           "citizens", "The citizens of the village are rushing in the streets.",
           "streets", "There are people rushing in the streets, though they look a bit narrow.",
           "sign", "A wooden sign attached to a column. You could probably read it."
          });

  smell="You feel the pine aroma in the air.";

}

init() {
  ::init(); 
  add_action("read_sign", "read");
}

read_sign(str1) {
  if (str1 != "sign") return;
  write("  Welcome in our village, brave adventurers!\n\n" +
        "  forest <-- village --> dark forest\n" +
        "                |\n" +
        "                |\n" +
        "                v\n" +
        "           corn plains\n");
  say(TPN + " reads the sign on the column.\n");
  return 1;
}

