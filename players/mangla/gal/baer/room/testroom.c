inherit "room/room";

#include "/players/mangla/defs.h"

reset(arg) {

    short_desc="Test Room";

    long_desc="Sample room for newbie wizzes to view and notice the coding " +
              "style used in. If this room were to go into the mud there " +
              "might actually be something worth reading in here, but as it " +
              "is there is not, you can just read this.\n";

    set_light(1);    /* minimum light level needed to see without     */
                     /*     a light source.  (Torch = 1 light level)  */

    items=({"nothing","You see alot of nothing in here",
            "room","Yep that is what it is",
          });

    property=({ "no_teleport" });   /* also availible no_fight and  */
                                    /*     no_steal and no_clean_up */

    smell="Since there is nothing else here, you smell your feet.\n";

    dest_dir=({"/players/baer/workroom","back",
               "/players/baer/tocheck.c", "check",
               "/players/baer/tocheck2.c", "check2",
               "players/baer/room/fishbowl","dive",
             });

    ::reset(arg);

    replace_program("room/room");
}

