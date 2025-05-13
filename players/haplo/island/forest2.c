inherit "room/room";
#include "/players/haplo/defs.h"


reset(arg)
{
    if(arg) return;

    set_light(1);
    short_desc="Island";
    long_desc=
     "You are on a north-south path through the forest. It is getting darker\n"+
     "the deeper into the forest you go. You can hear the water dripping from\n"+
     "the trees and you can see the puddles they are forming.\n";
    items=({
  "puddles","The puddles are slimy and stagnant you really don't want to touch it",
 "path","The path leads through the forest. You wonder who made it",
    });

  property=  ({
          });
    dest_dir=({
    ISLPATH+"forest3","north",
    ISLPATH+"forest1","south",
    });
}

init(){
    ::init();

}

