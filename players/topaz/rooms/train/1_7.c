inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    object dwarf;
    short_desc="A room in the Newbie Training Area";
    long_desc="This is a little room where a dwarf likes to relax.\n" +
              "If he is in, he would be a big challenge to help\n" +
              "you train yourself.\n";

    dest_dir=({TRAIN + "1_6","west",
    });
    items=({"room","A room for honing your fighting skills",
    });
    set_light(1);
    move_object(dwarf=clone_object(MNST + "train/newbie/dwarf"),this_object());
return 1;
  }
}
