inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Main Street";
    long_desc="This is toward the west end of Main Street.\n" +
              "The Allport post office is south of here.\n";

    dest_dir=({CONT + "post_office","south",
               CONT + "main_street1","west",
               CONT + "main_street3","east",
    });
    items=({"road","Very well used",
            "street","Very well used",
            "office","The Allport post office",
            "post office","The Allport post office",
            "post","The Allport post office",
    });
    set_light(1);
return 1;
  }
}
