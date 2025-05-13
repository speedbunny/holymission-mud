inherit "room/room";

#include "/players/mangla/defs.h"
#include "/players/mangla/rooms/newbie/random_veg.h"


reset(arg) {

    DUG = 5;

    if(arg) return;

    ::reset();

    short_desc = "Garden";

    long_desc = "The garden has been freshly weeded and watered so the\n" +
                "soil is loosely packed and soft under your feet. The\n" +
                "vegatables are full grown, but scattered through out the\n" +
                "expanse of the garden.\n";

    set_light(1);

    items = ({"soil","Very loose, perhaps you could search it",
              "dirt","Very loose, perhaps you could search it",
              "garden","The person who owns this place might not like you to\n" +
                       "dig up his garden",
              "wall","Surrounds the garden preventing wild animals from walking in",
            });

    property = ({ "no_teleport" });

    smell = "\nThe smell of newly turned earth greets you.\n";

    dest_dir = ({
//                 NEW + "garden1","west",
                 NEW + "garden22","east",
//                 NEW + "garden6","north",
                 NEW + "garden18","south",
              });

}


void init() {

    ::init();
    add_action("_search","search");
}
