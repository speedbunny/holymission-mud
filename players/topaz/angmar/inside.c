inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
object creature;
  if(!arg) {
    short_desc="Angmar's Castle";
    long_desc="You are inside the gates of Angmar the Necromancer's castle.\n" +
            "The castle was abandoned a long time ago when Angmar was driven\n" +
            "from earth by the Istari, and is now quite\n" +
            "ruined.You can see a forge to the west. A sign pointing\n" +
            "south says 'This way to fairyland'.\n";

    dest_dir=({PATH + "angmar/stairs","south",
               PATH + "angmar/forge","west",
                "room/crop5","north",
    });
    items=({"sign","It points south and says: This way to fairyland",
    });
    set_light(1);
    move_object(creature=clone_object(PATH + "angmar/creature"),TO);
    return 1;
  }
}
