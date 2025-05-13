inherit"room/room";
#include "../asgard.h"

reset(int arg)
{ ::reset(arg);
  if(!arg)
  { set_light(1);
    short_desc="Asgard land",
    long_desc="You are at the beginning of the Asgard land. To the north\n"+
              "you see Walhalla castle. The left arm brings you to the Asgard\n"+
              "land\n";
    
    dest_dir =({WIZ+"/port/pwalhalla","south",
                ROOM +"start002","north",
                ROOM +"start003","west"});

    smell = "You smell the fresh air";
  }
}
