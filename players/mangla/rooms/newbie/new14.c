inherit "room/room";

#include "/players/mangla/defs.h"

int strength;
int loose;
object ob1;

int _loosen(string arg) {

    if (!arg || arg != "mortar") return 0;

    printf("You begin to push and pry on the mortar, and eventually you\n");
    printf("think you have made some headway. Now to see if you can push\n");
    printf("the stone out of the way.\n");
    loose = 1;
    return 1;
}

int _push(string arg) {

    if (!arg && arg != "stone") return 0;

    if (!loose) {
        printf("Try as you might you cannot move the firmly mortared stone.\n");
        return 1;
    }
    if (strength) {
        printf("You push on the stone and it loosens, but does not fall out this time.\n");
        strength--;
        if (!strength) {
            printf("You give one last desperate shove and the stone rock out of\n");
            printf("the hole and you go tumbling through. As you right yourself\n");
            printf("you see the stone roll back into place.\n");
            TP->MOVEP("through a hole in the fence#"+NEW+"garden3");
            loose = 0;
        }
    }
    else {
        strength = TP->STR - 1;
        printf("You push on the stone and it loosens, but does not fall out this time.\n");
    }
    return 1;
}

reset(arg) {

    if(arg) return;

    ::reset();

    short_desc = "Forest";

    long_desc = "A rather large and peaceful forest where the birds are singing\n" +
                "and the flowers are in bloom. You marvel at the great expanse of\n" +
                "this beautiful wilderness. Small animals seem to rule this place,\n" +
                "and do not allow their more notorious and deadly kin to enter.\n" +
                "Never the less, some bad creatures do slip in at times. The towering\n" +
                "wall rises above you to the north. You can smell the fresh vegatables\n" +
                "on the other side.\n";

    set_light(1);

    items = ({"wilderness","Lush and vibrant, you can smell the freshness",
              "trees","Not too big, but growing fast. Maybe later you could climb them",
              "birds","Up in the tree tops out of reach",
              "animals","They are scampering all about, much too fast for you to catch",
              "grass","Sort of scarce in this part due to lack of sunlight",
              "wall","Large and imposing, stones piled up and filled with mortar",
              "mortar","Packed tight around most of the stones. Perhaps it could be loosened",
              "stones","Large rocks about the size of a player",
              "stone","Large rock about the size of a player",
            });

    property = ({ "no_teleport" });

    smell = "\nThe fresh aroma of the outdoors greets your olfactory sense.\n";

    dest_dir = ({
                 NEW + "new13","west",
                 NEW + "new9","south",
                 NEW + "new15","east",
              });

    if (!ob1) {
        ob1 = clone_object(MNST + "boar");
        MOVE(ob1,TO);
    }
}


void init() {

    ::init();
    add_action("_loosen","loosen");
    add_action("_push","push");
}
