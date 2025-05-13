inherit "room/room";
#include "/players/sylvyn/defines/amazon.h"

void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    set_light(1);
    short_desc="A village path.";
    long_desc=
    "This looks like the place the natives cure and store their food.\n" +
    "There is a small tent with a hole in the top with smoke coming\n" +
    "out of the top. You deduce that this must be where they smoke\n" +
    "thier meat to preserve it. There are other various skins on large\n" +
    "racks for tanning.\n" +
    "\n";

     dest_dir=({
         PATH+TRIBE+"a04.c", "north",
         PATH+TRIBE+"a12.c", "east",
         PATH+TRIBE+"a08.c", "west",

     });

     property = ({
       "no_teleport", "no_sneak", "no_steal",

     });

     items = ({
      "skins", "Large skins from animals stretched out to dry"
      "hut", "A small hut with no door and smoke coming out the top",

     });

    smell = "It smells like a mid-summer day.";

replace_program ("room/room");
}
