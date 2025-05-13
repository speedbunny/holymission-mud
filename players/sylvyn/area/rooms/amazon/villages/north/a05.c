inherit "room/room";
#include "/players/sylvyn/defines/amazon.h"

void reset(int arg) {
    ::reset(arg);
    if(arg) return;

    set_light(1);
    short_desc="A village path.";
    long_desc=
    "You have entered the garden area of the village. All around you\n" +
    "can see plants growing and some natives are cultivating the ground\n" +
    "to plant new crops. They do not even notice that you are there.\n" +
    "With the canopy of the forest just as dense here as elsewhere you\n" +
    "wonder how they get the plants to grow with such little light.\n" +
    "\n";

     dest_dir=({
         PATH+TRIBE+"a13.c", "north",
         PATH+TRIBE+"a12.c", "south",
         PATH+TRIBE+"a04.c", "west",

     });

     property = ({
       "no_teleport", "no_sneak", "no_steal",

     });

     items = ({
      "crops", "New buds of small crops just sprouting up from the ground.",
      "natives", "Women cultivating the ground, making room for new crops.",
      "canopy", "You see the splinters of light filtering down through.",

     });

    smell = "It's very moist with a heavy smell of manure.";

replace_program ("room/room");
}
