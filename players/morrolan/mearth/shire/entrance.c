/* Uglymouth 940117: changed all includes from <...> to "..." */
#include "mroom.h"
object board;

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "The entrance to the Shire";
    long_desc = 
    "Welcome to the Shire, the home of the hobbits or halflings as the men of\n"+
    "the Westernesse call them. This is a place where one can receive some\n"+
    "hospitality. The road leads north toward the Shire.\n";

    dest_dir = ({
      SHIRE+"/road1", "north",
      MET+"/tree2", "leave",
    });
    items = ({
      "sign", "Try reading it",
      "path", "A path leading north",
    });
}

