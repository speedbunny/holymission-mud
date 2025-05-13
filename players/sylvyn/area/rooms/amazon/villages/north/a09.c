inherit "room/room";
#include "/players/sylvyn/defines/amazon.h"

void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    set_light(1);
    short_desc="A village path.";
    long_desc=
    "Another typical village area. Tents and huts litter the landscape.\n" +
    "You never realized that so many people could live in one area! It\n" +
    "truly amazing! You see some small pets running around chasing some\n" +
    "unseen foe, most likely an insect of some sort.\n" +
    "\n";

     dest_dir=({
         PATH+TRIBE+"a11.c", "east",
         PATH+TRIBE+"a03.c", "south",
         PATH+TRIBE+"a07.c", "west",

     });

     property = ({
       "no_teleport", "no_sneak", "no_steal",

     });

     items = ({
       "dog", "Some dogs running around chasing what seems to be nothing"
       "huts", "Your average everyday hut"
       "tents", "Your average everyday tent"
     });

    smell = "It smells like a mid-summer day.";

replace_program ("room/room");
}
