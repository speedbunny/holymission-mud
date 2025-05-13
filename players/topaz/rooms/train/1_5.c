inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    object bunny;
    short_desc="A room in the Newbie Training Area";
    long_desc="A small white bunny lives here.\n" +
            "Not much of a challenge, huh?\n";

    dest_dir=({TRAIN + "1_6","east",
    });
    items=({"room","A room for honing your fighting skills",
    });
    set_light(1);
    smell="You smell bunny droppings.  Yuck!";
    move_object(bunny=clone_object(MNST + "train/newbie/bunny"),this_object());
return 1;
  }
}
