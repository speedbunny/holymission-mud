inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    object kitten;
    short_desc="A room in the Newbie Training Area";
    long_desc="This is the home of a cute little kitten.\n" +
              "A kitten shouldn't be that hard to kill.  Right?\n";

    dest_dir=({TRAIN + "1_3","east",
    });
    items=({"room","A room for honing your fighting skills",
    });
    set_light(1);
    smell="Smells like a kitten in here.";
    move_object(kitten=clone_object(MNST + "train/newbie/kitten"),this_object());
return 1;
  }
}
