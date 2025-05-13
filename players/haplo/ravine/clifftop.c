inherit "room/room";
#include "/players/haplo/defs.h"


reset(arg)
{
    if(arg) return;

    set_light(1);
    short_desc= "Ravine";
    long_desc=
   "Your standing on a ledge in the middle of the cliffside. The cliff wall\n"+
   "smooths out from here on up and is impossible to climb. The wind blows\n"+
   "with an eerie howl. There is an archway set into the wall here.\n";
    items=({
       "debris","The debris has been falling for years, hope nothing falls on you!!",
       "walls","The walls are time worn and smooth as glass. Climbing them would be foolish",
    });

  property=  ({
          });
    dest_dir=({
       "/players/haplo/ravine/ravine3","down"
    });
}

init(){
    ::init();

}

