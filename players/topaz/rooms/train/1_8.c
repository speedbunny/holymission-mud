inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    object bluejay;
    short_desc="A room in the Newbie Training Area";
    long_desc="A Blue Jay can often be found singing here.\n" +
              "If you see it, kill it!\n";

    dest_dir=({TRAIN + "1_9","east",
    });
    items=({"room","A room for honing your fighting skills",
    });
    set_light(1);
    smell="You smell bird droppings.";
    move_object(bluejay=clone_object(MNST + "train/newbie/bluejay"),this_object());
return 1;
  }
}
