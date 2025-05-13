inherit "room/room";

#include "/players/mangla/defs.h"

int PICKED;

int _gather(string str) {

    object obj;

    if(!str) return 0;

    if(str == "grass" || str == "fresh grass") {
        if (PICKED) {
            write("You gather some nice fresh grass, being careful to\n" +
                  "leave enough for all the rest of the animals.\n");
            obj = clone_object(OBJS + "grass");
            transfer(obj,TP);
            PICKED--;
        }
        else {
            write("You start to gather the grass and notice there really\n" +
                  "is not enough for you to take some and leave enough for\n" +
                  "the local animals.\n");
            PICKED = 0;
        }
        return 1;
    }
    return 0;
}

reset(arg) {

    PICKED = 4;

    if(arg) return;

    ::reset();

    short_desc = "Clearing";

    long_desc = "You have entered a large clearing in the center of " +
                "the woods. There is a large tree standing in the middle " +
                "of the clearing on its own, seperated from the " +
                "rest of the forest. Spreading out from the base of " +
                "the tree is a lush carpet of grass. The sunshine " +
                "streams down on you, but oddly enough it does not " +
                "seem hot here. You feel safe.\n";

    set_light(1);

    items = ({"tree","Large enough to climb, but not at this time",
              "trees","They surround this clearing",
              "carpet","A lush carpet of grass looks almost good enough to eat",
              "clearing","One of the most beautiful sights you have seen",
              "grass","Large green blades soak up the sunlight. You notice there\n" +
                      "is enough here to go around. So, if you gathered some, but\n" +
                      "was sure to leave enough for the other animals, it would\n" +
                      "be alright"
            });

    property = ({ "no_teleport" });

    smell = "\nThe fresh aroma of the outdoors greets your olfactory sense.\n";

    dest_dir = ({
                 NEW + "new3","south",
                 NEW + "new13","north",
                 NEW + "new9","east",
                 NEW + "new7","west",
              });

}


void init() {

    ::init();
    add_action("_gather","gather");
}
