inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(!arg) {
    short_desc="Angmar's experiment room";
    long_desc="Angmar used to use this room for all sorts of strange\n" +
              "experiments.  There are stains on the floor, walls and\n" +
              "ceiling.  Aside from that, there is nothing in this room.\n";

    dest_dir=({PATH + "angmar/midstairs","east",
               PATH + "angmar/library","west",
    });
    items=({"room","Angmar did many experiments here",
            "stains","From numerous explosions and spills",
            "floor","Covered with stains from spills",
            "walls","There are stains all over them",
            "wall","It has stains all over it",
            "ceiling","It has stains and scorch marks all over it",
            "mark","From an explosion long ago",
            "marks","From many explosions long ago",
    });
    set_light(0);
return 1;
  }
}
