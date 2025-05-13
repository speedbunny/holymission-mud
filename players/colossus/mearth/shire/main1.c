#include "mroom.h"

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "Main street 2";
    long_desc = 
    "You are on the main street of the Shire. To the north is a shop\n\
and to the west is a large oak tree. You are sure that those tiny\n\
figures under them are hobbits.\n";

    dest_dir = ({
      SHIRE+"/main2", "west",
      SHIRE+"/road3", "east",
      SHIRE+"/shop", "north",
    });

    items = ({
      "shop", "The general store of the Shire",
      "tree", "A large oak tree",
      "figures", "Lots of hobbits",
      "hobbits", "Yeah, those are the tiny figures under the tree",
    });
}
