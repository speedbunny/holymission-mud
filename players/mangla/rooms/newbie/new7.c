inherit "room/room";

#include "/players/mangla/defs.h"

object ob1,ob2,ob3,ob4;

reset(arg) {

    if(arg) return;

    ::reset();

    short_desc = "Forest";

    long_desc = "A rather large and peaceful forest where the birds are singing\n" +
                "and the flowers are in bloom. You marvel at the great expanse of\n" +
                "this beautiful wilderness. The forest gets lighter to the east\n" +
                "where you can make out a small clearing. Small animals seem to rule\n" +
                "this place, and do not allow their more notorious and deadly kin to enter.\n" +
                "Never the less, some mean and nasty creatures do slip in at times.\n";

    set_light(1);

    items = ({"wilderness","Lush and vibrant, you can smell the freshness",
              "trees","Not too big, but growing fast. Maybe later you could climb them",
              "birds","Up in the tree tops out of reach",
              "animals","They are scampering all about, much too fast for you to catch",
              "grass","Sort of scarce in this part due to lack of sunlight",
              "clearing","Bright with sunlight",
            });

    property = ({ "no_teleport" });

    smell = "\nThe fresh aroma of the outdoors greets your olfactory sense.\n";

    dest_dir = ({
                 NEW + "new2","south",
                 NEW + "new12","north",
                 NEW + "new8","east",
                 NEW + "new6","west",
              });

    if (!ob1 && !ob2 && !ob3 && !ob4) {
        ob1 = clone_object(MNST + "ssnake");
        MOVE(ob1,TO);
        ob2 = clone_object(MNST + "ssnake");
        MOVE(ob2,TO);
        ob3 = clone_object(MNST + "ssnake");
        MOVE(ob3,TO);
        ob4 = clone_object(MNST + "ssnake");
        MOVE(ob4,TO);
    }
}


void init() {

    ::init();
}
