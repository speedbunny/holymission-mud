inherit"room/room";
#include "../asgard.h"

reset(int arg)
{ ::reset(arg);
  if(!arg)
  { set_light(1);
    short_desc="Asgard land",
    long_desc="You are at the beginning of the Asgard land.\n"+
              "Walhalla castle is north of you. In the south you see a arm\n"+
              "leading to the west.\n"; 
   dest_dir= ({ WIZ+"/valhalla/room/bridge","northeast",
                ROOM +"start001","south",
              });

    smell = "You smell the fresh air";
  }
}
