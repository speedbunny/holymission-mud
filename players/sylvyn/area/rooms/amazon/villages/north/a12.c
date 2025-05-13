inherit "room/room";
#include "/players/sylvyn/defines/amazon.h"

void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    set_light(1);
    short_desc="A village path.";
    long_desc=
    "You have walked into what appears to be where the natives keep their\n" +
    "livestock! PHEW!!! Does it stink in here. You can tell that this is\n" +
    "where they got there manure. You can see some cows and pigs in a \n" +
    "fenced in area. Agian you wonder where did they get such animals.\n" +
    "No animals exsist in this forrest.\n" +
    "\n";

     dest_dir=({
         PATH+TRIBE+"a05.c", "north",
         PATH+TRIBE+"a10.c", "west",

     });

     property = ({
       "no_teleport", "no_sneak", "no_steal",

     });

     items = ({
      "cows", "A large ugly brown cow.",
      "pig", "A big dirty smelly pig.",
      "fence", "A large pole fence, very sturdy.",

     });

    smell = "It smells like maneur.";

replace_program ("room/room");
}
