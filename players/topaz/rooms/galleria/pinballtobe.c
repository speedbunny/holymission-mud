inherit "room/room";

#include "/players/topaz/defs.h"

int _play(string arg) {
    if(!arg) {
        notify_fail("Play what?\n");
    }
    if(arg=="pinball"||arg=="pinball machine"||arg=="machine") {
        int busy,score,cost,continue;
        busy=1;
        score=0;
        cost=5;
        continue=1;
        IFBUSY
        ELSE
        SOMEOTHERSTUFF
        MORESTUFF
    }
    else notify_fail("Play what?\n");
    return 1;
}

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Pinball Room";
    long_desc="This is a room specifically designed to play pinball in.\n" +
              "You should try the pinball machine out.  :)\n";

    dest_dir=({GALL + "rooms/hallway2_1.c","south",
    });
    items=({"room","It's made only for playing pinball",
    });
    set_light(1);
    move_object(clone_object(OBJS + "galleria/pinball"),TO);
return 1;
  }
}

init(){
  ::init();

        add_action("_play","play");
}
