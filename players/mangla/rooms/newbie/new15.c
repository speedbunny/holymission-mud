inherit "room/room";

#include "/players/mangla/defs.h"

object ob1,ob2;

reset(arg) {

    if(arg) return;

    ::reset();

    short_desc = "Forest";

    long_desc = "A rather large and peaceful forest where the birds are singing " +
                "and the flowers are in bloom. You marvel at the great expanse of " +
                "this beautiful wilderness.  The only thing obscuring the serinity " +
                "is the wall and a small path leading east out of the forest. Small " +
                "animals seem to rule this place, and do not allow their more " +
                "notorious and deadly kin to enter.\n" +
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
                 NEW + "new14","west",
                 NEW + "new10","south",
//                 NEW + "new5","east",
              });

    hidden_dir = ({
                   "/players/muzmuz/quest/connect","east",
                 });


    if (!ob1 && !ob2) {
        ob1 = clone_object(MNST + "wolf");
        MOVE(ob1,TO);
        ob2 = clone_object(MNST + "wolf");
        MOVE(ob2,TO);
    }
}


void init() {

    ::init();
}

