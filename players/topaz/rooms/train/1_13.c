inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    object puppy;
    short_desc="A room in the Newbie Training Area";
    long_desc="A cute puppy can sometimes be found playing here.\n" +
              "If you see it, show your stuff and kill it!\n";

    dest_dir=({TRAIN + "1_12","west",
    });
    items=({"room","A room for honing your fighting skills",
    });
    set_light(1);
    smell="Smells like a puppy in here.";
    move_object(puppy=clone_object(MNST + "train/newbie/puppy"),this_object());
return 1;
  }
}
