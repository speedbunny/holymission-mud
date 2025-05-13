#include "mroom.h"

reset(arg){
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "Entrance to Frodo's";
    long_desc =
    "You're at the end of Bag End. You're standing in front of Frodo's hole\n"+
    "and you see an immaculate garden, a door you can just squeeze into, and\n"+
    "smoke coming out of the chimney.\n";
    dest_dir = ({
      SHIRE+"/frodo_house1", "north",
      SHIRE+"/bagend2", "south",
    });
    items = ({
      "hole", "A typical hobbit house",
      "garden", "Wow, talk about nice gardens",
      "door", "A small door that you can just squeeze in",
      "smoke", "Smoke coming out of the chimney. Someone must be in",
      "chimney", "A chimney with smoke coming out",
    });
}
