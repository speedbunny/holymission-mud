inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    object giant;
    short_desc="A room in the Newbie Training Area";
    long_desc="This room is pretty big.  That's because it's a baby giant's\n" +
              "room.  He'll be a challenge for you to kill, if he's here.\n";

    dest_dir=({TRAIN + "1_12","south",
    });
    items=({"room","A room for honing your fighting skills",
    });
    set_light(1);
    smell="It doesn't smell very good in here.";
    move_object(giant=clone_object(MNST + "train/newbie/giant"),this_object());
return 1;
  }
}
