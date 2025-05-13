#include "mroom.h"

reset(arg){
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "South of inn";
    long_desc = 
    "You are on a path that branches in four different directions.\n"+
    "The highly reputed inn, The Green Dragon, is directly to the north\n"+
    "and to the west you believe you see a body of water and some sort\n"+
    "of pier. To the south is the beginning of a forest.\n";
    dest_dir = ({
      SHIRE+"/inn", "north",
      SHIRE+"/main2", "east",
      SHIRE+"/pier1", "west",
      SHIRE+"/forest1", "south",
    });
    items = ({
      "inn", "The Green Dragon",
      "forest", "The beginnings of a forest starts to the south",
      "pier", "A pier of some sort, perhaps you can get a boat ride",
      "water", "It's a fairly small lake, actually a pond",
    });
}
