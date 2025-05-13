inherit "room/room";

#include "/players/mangla/defs.h"

void reset(int arg) {

    short_desc = "New Mud Layout Discussion";

    long_desc = "The mud will be going through some changing times in " +
                "the near future and we, as the mud administrators, " +
                "would like to lay out some of these designs and get " +
                "player feedback as to how they should, or should not " +
                "proceed. In the near future the new town layout will " +
                "be availible from this room. For now, please just " +
                "post your ideas and comments regarding one more " +
                "mud reorganization. Note: With this reorg there " +
                "will be help files containing full and partial " +
                "mud maps. Individual wizards will be encouraged " +
                "to supply maps of thier areas, with the precaution " +
                "that area maps do not infringe on or offer " +
                "quest information. Check back here for more details" +
                "as they are know.\n";

    set_light(1);

    items = ({
            });

    property = ({
                 "no_teleport",
                 "no_clean_up",
                 "no_sneak",
               });

    dest_dir = ({
                  "room/church","out"
               });

    clone_list = ({
                   1, 1, "board", "boards/new_layout" , 0,
                 });

    ::reset();
    replace_program("room/room");
}
