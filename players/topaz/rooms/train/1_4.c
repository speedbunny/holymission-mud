inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    object lizard;
    short_desc="A room in the Newbie Training Area";
    long_desc="A little lizard usually rests on some rocks here.\n" +
              "If you see it, hone your skills by killing it.\n";

    dest_dir=({TRAIN + "1_3","west",
    });
    items=({"room","A room for honing your fighting skills",
            "rocks","They are warm.  Perfect for a lizard to sit on",
    });
    set_light(1);
    smell="It smells like a lizard in here.";
    move_object(lizard=clone_object(MNST + "train/newbie/lizard"),this_object());
return 1;
  }
}
