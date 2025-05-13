inherit "room/room";
#include "/players/haplo/defs.h"


reset(arg)
{
    if(arg) return;

    set_light(1);
    short_desc= "Ravine";
    long_desc=
     "Your are in a deep ravine running north and south. The walls are steep and\n"+
     "smooth and you could not scale them even if you wanted to. The ravine path\n"+
      "is worn into the rock and littered with pebbles and other lose debris that has\n"+
     "fallen over the years.\n";
    items=({
       "debris","The debris has been falling for years, hope nothing falls on you!!",
       "walls","The walls are time worn and smooth as glass. Climbing them would be foolish",
    });

  property=  ({
          });
    dest_dir=({
        "/players/haplo/ravine/ravine3","south",
        "/players/haplo/ravine/ravine5","north"
    });
}

init(){
    ::init();

}

