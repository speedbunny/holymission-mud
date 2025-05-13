#include "mroom.h"

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "North Bag End";
    long_desc =
    "You're on North Bag End and you see a garden that's being mowed by a\n"+
    "young hobbit to the east of you. You feel curiosly drawn to this\n"+
    "house. To the north is the house of Frodo and Bilbo Baggins.\n";

    dest_dir = ({
      SHIRE+"/sam", "east",
      SHIRE+"/frodo_entrance", "north",
      SHIRE+"/bagend1", "south",
    });

    items = ({
      "garden", "Just another neatly kept garden",
      "gate", "A nice white gate",
    });
}
