#include "abbey.h"
inherit "room/room";

reset(arg) {
int i;
  if (!arg) {
     set_light(1);
     short_desc="Unburnt Stake";
     long_desc=
"You stand before a mound of earth, topped by a heap of sticks.\n"+
"There is a large stake upright in the center, with several strands\n"+
"of rope at it's base.\n";
     dest_dir=({ PATH+"/o18t1","northwest" });
  }
  if (!(present("torch")))
     for(i=0;i<3;i++)
	move_object(clone_object("obj/torch"),this_object());
}
