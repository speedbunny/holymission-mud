#include "mroom.h"

void reset(int arg){
    ::reset(arg);
    if(arg) return ;
    set_light(1);
    short_desc = "Main road";
    long_desc =
    "You are on the main street. Further up this street you see it connecting\n"+
    "to other streets. You also see a large tree in the distance with several\n"+
    "tiny figures under it.\n";

    dest_dir = ({
      SHIRE+"/main1", "west",
      SHIRE+"/road2", "east",
    });
    items = ({
      "streets", "Nice streets",
      "tree", "A large oak tree",
      "figures", "You think they look like hobbits",
    });
}
