inherit "room/room";

#include "/players/mangla/defs.h"

void reset(int arg) {

    short_desc = "Wizard's flame room";

    long_desc = "You are in the wizard's flame room. " +
               "The hottest discussions will be fought out here.\n";

    set_light(1);

    items = ({
            });

    property = ({
                 "no_teleport",
                 "no_clean_up",
                 "no_sneak",
               });

    dest_dir = ({
                  "/room/wiz/general","up"
               });

    clone_list = ({
                   1, 1, "board", "boards/wiz_flame" , 0,
                 });

    ::reset();
    replace_program("room/room");
}
