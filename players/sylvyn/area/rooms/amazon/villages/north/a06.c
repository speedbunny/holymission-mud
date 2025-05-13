inherit "room/room";
#include "/players/sylvyn/defines/amazon.h"

void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    set_light(1);
    short_desc="A village path.";
    long_desc=
    "A small open field where the kids are allowed to run and play.\n" +
    "There seems to be some sort of game going on, for the children\n" +
    "do not notice your presence. You are very intrigued by their\n" +
    "antics though.\n" +
    "\n";

     dest_dir=({
         PATH+TRIBE+"a02.c", "north",
         PATH+TRIBE+"a08.c", "east",

     });

     property = ({
       "no_teleport", "no_sneak", "no_steal",

     });

     items = ({
      "field", "A large open grassy field."
      "kids", "A large group of kids frolicing arourd playing a game.",

     });

    smell = "It smells like a mid-summer day.";

replace_program ("room/room");
}
