inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Main Street";
    long_desc="This is the west end of Main Street.\n" +
              "West Road is south from here.\n";

    dest_dir=({CONT + "main_street2","east",
               CONT + "west_road3","south",
    });
    items=({"road","This corner has seen much use",
            "street","This corner has seen much use",
            "corner","Corner of Main and West",

            
    });
    set_light(1);
return 1;
  }
}
