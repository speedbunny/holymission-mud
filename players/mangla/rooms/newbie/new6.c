inherit "room/room";

#include "/players/mangla/defs.h"

object ob1;

reset(arg) {

    if(arg) return;

    ::reset();

    short_desc = "Forest";

    long_desc = "A rather large and peaceful forest where the birds are singing\n" +
                "and the flowers are in bloom. You marvel at the great expanse of\n" +
                "this beautiful wilderness. Small animals seem to rule this place,\n" +
                "and do not allow their more notorious and deadly kin to enter.\n" +
                "Never the less, some bad creatures do slip in at times. No wall,\n" +
                "even the one you can see surrounding this place, is perfect.\n";

    set_light(1);

    items = ({"wilderness","Lush and vibrant, you can smell the freshness",
              "trees","Not too big, but growing fast. Maybe later you could climb them",
              "birds","Up in the tree tops out of reach",
              "animals","They are scampering all about, much too fast for you to catch",
              "grass","Sort of scarce in this part due to lack of sunlight"
            });

    property = ({ "no_teleport" });

    smell = "\nThe fresh aroma of the outdoors greets your olfactory sense.\n";

    dest_dir = ({
                 NEW + "new1","south",
                 NEW + "new11","north",
                 NEW + "new7","east",
              });

    if (!ob1) {
        ob1 = clone_object(MNST + "boar");
        MOVE(ob1,TO);
    }
}


void init() {

    ::init();
}
