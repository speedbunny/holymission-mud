inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Main Street";
    long_desc="This is Allport's Main Street.\n" +
              "The forest is north of here and the Sheriff's\n" +
              "office is south.\n";

    dest_dir=({CONT + "sheriff","south",
               FOREST + "forest1","north",
               CONT + "main_street2","west",
               CONT + "main_street4","east",
    });
    items=({"road","It is wide to accomodate much traffic",
            "street","It is wide to accomodate much traffic",
            "forest","You can enter it by going north",
            "office","That's the Sheriff's office",
    });
    set_light(1);
return 1;
  }
}
