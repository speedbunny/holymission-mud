inherit "room/room";
#include "/players/sylvyn/defines/amazon.h"

void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    set_light(1);
    short_desc="A village path.";
    long_desc=
    "A small empty area of the village. There is really not much of\n" +
    "anything here. A few huts lie to your north a the vast forest\n" +
    "lies to your south.\n" +
    "\n";

     dest_dir=({
         PATH+TRIBE+"a03.c", "north",
         PATH+TRIBE+"a10.c", "east",
         PATH+TRIBE+"a06.c", "west",

     });

     property = ({
       "no_teleport", "no_sneak", "no_steal",

     });

     items = ({
      "forest", "The deep dark Nyrooubian Forest"
      "huts", "Some small huts that the natives live in",

     });

    smell = "It smells like a mid-summer day.";

replace_program ("room/room");
}

