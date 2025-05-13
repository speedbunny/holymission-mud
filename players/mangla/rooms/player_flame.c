inherit "room/room";

#include "/players/mangla/defs.h"

void reset(int arg) {

    short_desc = "Players flame room";

    long_desc = "This is the players flame room where " +
                " players come if they want to complain " +
                " about something.\n";

    set_light(1);

    items = ({
            });

    property = ({
                 "no_teleport",
                 "no_clean_up",
                 "no_sneak",
               });

    dest_dir = ({
                  "room/adv_guild","up"
               });

    clone_list = ({
                   1, 1, "board", "boards/player_flame" , 0,
                 });

    ::reset();
    replace_program("room/room");
}
