inherit "room/room";

#include "/sys/levels.h"
#include "/players/mangla/defs.h"

int _open(string str) {

    if(!str) return 0;

    if(str == "gate") {
        if ((TP->LEVEL < L_APPR && TP->LEVEL > 5) && (TP->query_quests("guineapig"))) {
            printf("You try with all your might but the gate will not open for you.\n");
        }
        else {
            printf("You open the gate, enter, and close it behind you.\n");
            TP->MOVEP("through the gate#players/mangla/rooms/newbie/new1");
        }
        return 1;
    }
    return 0;
}

reset(arg) {

    if(arg) return;

    ::reset();

    short_desc = "Clearing";

    long_desc = "You are standing outside a large forest. It seems a peaceful\n" +
                "and serene setting where the small animals can play. To the\n" +
                "south is the town from which you have just recently arrived. \n\n" +
                "There is a large gate to the north. Just open it to enter.\n";

    set_light(1);

    items = ({"forest","Lush and vibrant. It seems like paradise",
              "clearing","Where you are standing, before the gate",
              "village","South of you it stretches off into the distance",
              "gate","A very sturdy gate that does not allow oafish high\n" +
                     "level players to enter and disturb the peace",
              "animals","In general, small and cuddly, but some are not"
            });

    property = ({ "no_teleport" });

    smell = "\nThe fresh aroma of the outdoors greets your olfactory sense.\n";

    dest_dir = ({
                 "/players/bobo/krooms/vill/road3","south",
//                 NEW + "new6","north",
//                 NEW + "new2","east",
              });

}


void init() {

    ::init();
    add_action("_open","open");
}
