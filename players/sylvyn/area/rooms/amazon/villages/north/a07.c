inherit "room/room";
#include "/players/sylvyn/defines/amazon.h"

void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    set_light(1);
    short_desc="A village path.";
    long_desc=
    "The first thing you notice here is all of the huts scattered about\n" +
    "all over the place. You realize this must be where all of the\n" +
    "sleeping quarters must be.  There is a large tent in the middle.\n" +
    "It's 3 times the size of any of the others. You figure that it must\n" +
    "be the main meeting hall.\n" +
    "\n";

     dest_dir=({
         PATH+TRIBE+"a09.c", "east",
         PATH+TRIBE+"a02.c", "south",

     });

     property = ({
       "no_teleport", "no_sneak", "no_steal",

     });

     items = ({
      
     });

    smell = "It smells like a mid-summer day.";

replace_program ("room/room");
}
