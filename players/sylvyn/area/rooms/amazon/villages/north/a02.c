inherit "room/room";
#include "/players/sylvyn/defines/amazon.h"

void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    set_light(1);
    short_desc="A village path.";
    long_desc=
    "You are standing in what seems to be the main pathway of the\n" +
    "village. There are many natives moving around, all keeping a\n" +
    "wary eye on you. The children are standing behind there mothers\n" +
    "in fear from your presence. You notice that many of the men are\n" +
    "carrying spears. There is a strange smell in the air.\n" +
    "\n";

     dest_dir=({
         PATH+TRIBE+"a07.c", "north",
         PATH+TRIBE+"a03.c", "east",
         PATH+TRIBE+"a06.c", "south",
         PATH+TRIBE+"a01.c", "west",

     });

     property = ({
       "no_teleport", "no_sneak", "no_steal",

     });

     items = ({
       "path", "A dusty well worn path in the village.",
       "children", "Small girls and boys hiding behind their mother\n" +
       "seeking her protection.\n",
       "mothers", "A native woman dressed in dear skins from head to\n" +
       "toe. Rather pretty looking actually.\n",
       "men", "Large powerfully built muscular men, eyeing you like\n" +
        "you are some sort of evil come to take there women.\n",

     });

    smell = "It smells like smoke, but you notice a different aroma..\n" +
            "you got it!! Dog dropings!!! You suddenly notice your\n" +
            "standing in a pile. YUCK!\n";

replace_program ("room/room");
}
