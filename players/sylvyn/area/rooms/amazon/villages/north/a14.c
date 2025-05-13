inherit "room/room";
#include "/players/sylvyn/defines/amazon.h"

void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    set_light(1);
    short_desc="A village path.";
    long_desc=
    "You have entered the chamber of the Tribal Chief. The Chief sits\n" +
    "upon a large wooden throne. There are four guards on his left and\n" +
    "right. You notice a diamond on a leather thong around his neck. You\n" +
    "suddenly realize that that is one of the stones to open the portal\n" +
    "to the ancient temple.\n" +
    "\n";

     dest_dir=({
        PATH+TRIBE+"a13.c", "west",

     });

     property = ({
       "no_teleport", "no_sneak", "no_steal",

     });

     items = ({
       "guard", "A huge guard with a very large spear in his hands",
       "diamond", "A huge diamond with a magical glow",
       "chief", "A large man holding a large stone axe",
       "throne", "A majestic throne of entwined vines and branches", 

     });

    smell = "A light sent of fragrence fills the air.";

replace_program ("room/room");
}
