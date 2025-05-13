inherit "room/room";

#include "/players/mangla/defs.h"

reset(arg) {

    short_desc = "Large Rock Cave";

    long_desc = "A large rock cave surrounds you, and the heat is so\n" +
                "intense your skin feel as if it is being burned from\n" +
                "your bones. At a glance you would assume this is due\n" +
                "to the great Wyrm that currently occupies this place.\n";

    set_light(1);

    items = ({ "cave","Large abode of a fearsome Wyrm",
               "heat","So intense you can see it",
            });

    property = ({ "no_teleport" , "no_clean_up" });

    smell="\nA fresh breeze assails your nose.\n";

    dest_dir = ({ ROOM + "mount/rock12","east",
//               ROOM + "mount/rock0","up",
             });

    clone_list = ({ 1, 1, "dragon", MNST + "dragon", 0,
                 });

    ::reset();
    replace_program("room/room");
}
