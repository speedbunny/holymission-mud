inherit "room/room";

#include "/players/mangla/defs.h"
#include "/players/mangla/rooms/newbie/random_veg.h"


reset(arg) {

    DUG = 3;

    if(arg) return;

    ::reset();

    short_desc = "Garden";

    long_desc = "The garden has been freshly weeded and watered so the\n" +
                "soil is loosely packed and soft under your feet. The\n" +
                "vegatables are full grown, but scattered throughout.\n" +
                "There is a little ladder against the wall south of you\n" +
                "allowing you to get out of the garden over the wall.\n";

    set_light(1);

    items = ({"soil","Very loose, perhaps you could search it",
              "dirt","Very loose, perhaps you could search it",
              "garden","The person who owns this place might not like you to\n" +
                       "dig up his garden",
              "wall","Surrounds the garden preventing wild animals from walking in",
              "ladder","Just high enough to reach the top of the wall",
            });

    property = ({ "no_teleport" });

    smell = "\nThe smell of newly turned earth greets you.\n";

    dest_dir = ({
                 NEW + "garden2","west",
                 NEW + "garden7","north",
                 NEW + "garden4","east",
                 NEW + "new14","south",
              });

}


void init() {

    ::init();
    add_action("_search","search");
}
