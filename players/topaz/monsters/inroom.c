inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    object inmon;
    short_desc="Standard Room";
    long_desc="This is a standard room.\n";

    dest_dir=({PATH + "workroom","south",
               PATH + "workroom","north",
    });
    items=({"room","A standard room",
    });
    set_light(1);
    smell="You smell nothing special.";
    move_object(inmon=clone_object(MNST + "in"),this_object());
    inmon->set_invis();
return 1;
  }
}
