#include "mroom.h"

void reset(int arg){
    if(arg) return;
    set_light(1);
    short_desc = "Frodo's living room";
    long_desc =
    "This is Frodo and Bilbo's living room. The place is tastefully decorated\n"+
    "and has pictures, wood carvings, and a nice fire in the fireplace.\n"+
    "You feel totally at home and could just stay forever in this snug and cozy\n"+
    "place. It looks like Frodo has some guests today.\n";
    dest_dir = ({
      SHIRE+"/frodo_house2", "north",
      SHIRE+"/frodo_entrance", "south",
    });
    items = ({
      "pictures", "Pictures of hobbits, trees, and lots of other nice things",
      "carvings", "Wood carvings of domestic animals, hobbits, and other things",
      "fire", "Wow, a nice fire that just warms your bones",
    });
    clone_list = ({1,1,"gimli", SHIRE+"/gimli", 0,
      2,1, "legolas", SHIRE+"/legolas", 0});
    property = "has_fire";
    ::reset();
    replace_program("room/room");
}

void light_text(string str){
    write("You hold the " + str + " near the fireplace and light it.\n");
}
