inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    object cockroach;
    short_desc="A room in the Newbie Training Area";
    long_desc="Yeck!  This room stinks and is filthy!\n" +
              "If there a cockroach here, waste him!\n";

    dest_dir=({TRAIN + "1_9","west",
    });
    items=({"room","A room for honing your fighting skills",
    });
    set_light(1);
    smell="Eww!  Your nose hates you now!  It smells really bad in here!";
    move_object(cockroach=clone_object(MNST + "train/newbie/cockroach"),this_object());
return 1;
  }
}
