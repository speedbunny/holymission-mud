inherit "room/room";
#include "/players/haplo/defs.h"


reset(arg)
{
    if(arg) return;

    set_light(1);
    short_desc="Island";
    long_desc=
 "You stand before a door leading into what looks like a small pyramid. The \
  wind is whipping around you stirring up the desert sand. The sun continues to \
  beat mercilessly down on you.\n";
    items=({
  "puddles","The puddles are slimy and stagnant you really don't want to touch it",
 "path","The path leads through the forest. You wonder who made it",
    });

  property=  ({
          });
    dest_dir=({
          ISLPATH+"forest2","north",
    });
}

init(){
    ::init();

}

