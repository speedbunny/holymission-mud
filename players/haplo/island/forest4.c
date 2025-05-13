inherit "room/room";
#include "/players/haplo/defs.h"


reset(arg)
{
    if(arg) return;

    set_light(0);
    short_desc="Island";
    long_desc=
    "The forest is so dark here you can't see without light. The path continues\n"+
    "deeper into the ever thickening foliage. You notice that it is also very quiet\n"+
    "around here.\n";
    items=({
  "foliage","Thick twisted plant growth covers the roof of the path forming a tunnel",
 "path","The path leads through the forest. You wonder who made it",
    });

  property=  ({
          });
    dest_dir=({
    });
}

init(){
    ::init();

}

