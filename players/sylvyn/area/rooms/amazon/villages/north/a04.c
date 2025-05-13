inherit "room/room";
#include "/players/sylvyn/defines/amazon.h"

void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    set_light(1);
    short_desc="A village path.";
    long_desc=
    "You are standing a pathway in the village. There is a lot of\n" +
    "natives here busy at doing simple tasks like making clothes and\n" +
    "weapons and pottery. They pay little or no attention to your\n" +
    "presence. You also notice what seems to be magical items in the\n" +
    "opening of one of the tents. There are two very BIG guards in\n" +
    "front of that door.\n" +
    "\n";

     dest_dir=({
         PATH+TRIBE+"a11.c", "north",
         PATH+TRIBE+"a05.c", "east",
         PATH+TRIBE+"a10.c", "south",
         PATH+TRIBE+"a03.c", "west",

     });

     property = ({
       "no_teleport", "no_sneak", "no_steal",

     });

     items = ({
      "path", "A dusty well worn path in the village.",
      "weapons", "Very sharp, almost magically sharp looking stones.",
      "pottery", "Simple clay pottery used to store things in.",
      "clothes", "Deek skin shirts and pants. All very well made!",
      "guard", "Two huge well muscled rock solid guards.",


     });

    smell = "Its very dusty with just a hint of smoke in the air.";

replace_program ("room/room");
}
