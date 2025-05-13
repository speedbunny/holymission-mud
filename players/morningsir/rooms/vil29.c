inherit "/room/room";

#include "/players/morningsir/defs.h"

reset(arg) {
  if(!arg) {

  set_light(1);
  short_desc="Corn fields view.";
  long_desc=
    "You have arrived to a place with a good sight at the southern corn fields.\n" +
    "The village itself lies in northern direction and a distance mixture of\n" +
    "sounds from the northeast comes from the main square. There is a NOTE lying\n" +
    "on the dirty road, telling some bad news.\n";

  dest_dir=({ PATHR + "vil28.c", "north"
             });

  items=({ "village", "The village looks alive.",
           "houses", "The houses are made of wood and they look old.",
           "note", "There is written: THE FIELDS ARE UNDER CONSTRUCTION."
          });

  smell="You can feel Morningsir's strong lazyness in the air drifting from south.";

  }
  replace_program("room/room");
}
