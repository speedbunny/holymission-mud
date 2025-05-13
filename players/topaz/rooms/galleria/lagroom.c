inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
    if(!arg) {
    set_light(1);
    short_desc="The Lag Monster's lair";
    long_desc="You have entered the lair of the dreaded, hated\n" +
              "and despised Lag Monster!  Be careful!  Many brave\n" +
              "adventurers have succumbed to the awesome power of the\n" +
              "powerful Lag Monster!!!\n" +
              "You should probably leave while you still can!\n";
    items=({"lair","The Lag Monster lives here!  You better leave quickly"});
    dest_dir=({"players/topaz/workroom", "east"});
    smell="It smells stagnant and stale in here.";
    extra_reset();
    }
}

extra_reset() {
object lag;

    if(present("lag",this_object())) return;
    if(!present("lag",this_object())) {
      lag=clone_object(GALL + "monsters/lagmonster");
      move_object(lag,this_object());
    }
}
