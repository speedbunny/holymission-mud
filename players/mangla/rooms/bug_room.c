inherit "room/room";

#include "/players/mangla/defs.h"

void reset(int arg) {

  short_desc = "Bug Room";

  long_desc = "This is a bug room. Several of them are crawling " +
              "around the mud and need squished. Please let us " +
              "know where you see these nasty bugs and any " +
              "special actions you took to make them happen.\n";

    set_light(1);

    items = ({
            });

    property = ({
                 "no_teleport",
                 "no_clean_up",
                 "no_sneak",
               });

    dest_dir = ({
                 "room/adv_guild","northeast"
               });

    clone_list = ({
                   1, 1, "board", "boards/player_bug" , 0,
                 });

    ::reset();
    replace_program("room/room");
}
