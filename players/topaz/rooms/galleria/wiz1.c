inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Hall of Wizards";
    long_desc="This is the Galleria's Hall of Wizards.\n" +
              "Models of all of the Wizards on this mud are here.\n" +
              "You see all your favorite Wizards (plus the ones you don't\n" +
              "like).  Of course, there's Topaz.  His model is first in\n" +
              "line.\n";

    dest_dir=({GALL + "hallway1_1","east",
    });
    items=({"model","The model of Topaz is awe inspiring!\n" +
                    "You could just stand here and look at it for hours",
            "models","They are all very impressive",
    });
    set_light(1);
return 1;
  }
}
