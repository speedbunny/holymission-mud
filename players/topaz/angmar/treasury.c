inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Angmar's treasury";
    long_desc="This is Angmar's treasury room.\n" +
              "It used to be full of every sort of treasure imaginable!\n" +
              "But, unfortunately, over the years people have stolen\n" +
              "everything.  There's nothing here now.\n";

    dest_dir=({PATH + "angmar/midstairs","south",
    });
    items=({"treasury","It is empty now",
    });
    set_light(1);
    move_object(clone_object(PATH + "angmar/thief"),TO);
return 1;
  }
}
