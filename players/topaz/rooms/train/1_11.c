inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    object troll;
    short_desc="A room in the Newbie Training Area";
    long_desc="This is a small cave.  Any trolls around might not\n" +
               "appreciate you being here!\n";

    dest_dir=({TRAIN + "1_12","east",
    });
    items=({"room","A room for honing your fighting skills",
    });
    set_light(1);
    smell="It smells a little foul in here.";
    move_object(troll=clone_object(MNST + "train/newbie/troll"),this_object());
return 1;
  }
}
