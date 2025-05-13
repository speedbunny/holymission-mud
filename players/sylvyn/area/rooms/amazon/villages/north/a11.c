inherit "room/room";
#include "/players/sylvyn/defines/amazon.h"

void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    set_light(1);
    short_desc="A village path.";
    long_desc=
    "It is very quiet here. Nothing but the foliage and wildlife. There\n" +
    "are no natives, or dogs or anything. Just barren landscape.\n" +
    "\n";

     dest_dir=({
         PATH+TRIBE+"a13.c", "east",
         PATH+TRIBE+"a04.c", "south",
         PATH+TRIBE+"a09.c", "west",

     });

     property = ({
       "no_teleport", "no_sneak", "no_steal",

     });

     items = ({
       
     });

    smell = "It smells like a mid-summer day.";

replace_program ("room/room");
}
