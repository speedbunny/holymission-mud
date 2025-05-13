inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="West Road";
    long_desc="You are at the end of West Road.\n" +
              "The 'Rough and Tumble' bar is southwest of here and\n" +
              "you could probably get something good to drink in there.\n";

    dest_dir=({CONT + "fight_bar","southwest",
               CONT + "west_road2","northeast",
    });
    items=({"road","A dimly lit road",
            "bar","Looks like a tough crowd in there",
    });
    set_light(1);
return 1;
  }
}
