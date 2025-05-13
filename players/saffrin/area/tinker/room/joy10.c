inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg) {
    set_light(2);
    short_desc="Joy's Park";
    long_desc=
         "You are standing at the north edge of Joy's Park.  You can hear the trickling "+
         "of water to the southeast.  There are several butterflies fluttering about, "+
         "sipping pollen from a few flowers.  The green grass has several droplets of "+
         "dew gleeming on them.\n";
    dest_dir = ({
      TINK+"room/joy11", "south",
      TINK+"room/joy1", "east",
      TINK+"room/joy9", "west",
    });
    items =({
      "butterflies", "Severl colorful butterflies collecting pollen",
      "pollen", "Sweet life of a flower",
      "flowers", "Sweet smelling flowers",
      "grass", "Green grass with dew droplets on them",
      "dew", "Moist droplets",
      "droplets", "Moist spots of dew",
    });
    clone_list=({
          1, 3, "butterfly", TINK+"npc/butterfl", 0,
    });
    ::reset();
    replace_program("room/room");
}
