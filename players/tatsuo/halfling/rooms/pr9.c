inherit "room/room";
#include "/players/tatsuo/def.h"

void reset(int arg){

if(!present("fisherman")){
MO(CO(HMON+"fisherman"),TO);
MO(CO(HMON+"fisherman"),TO);
MO(CO(HMON+"hchild"),TO);
}

if(arg) return;
  ::reset(arg);

  set_light(1);

  long_desc = "The valley begins to flaten out here.  The piers still "+
              "fill the river's edge along the path here"+
              ".\n";

  short_desc= "Along the Shayla river";

  dest_dir = ({ HPATH+"pr8","north", HPATH+"pr10","south" });

  items = ({  "valley","Umm, the valley is to the north",
              "river","Same ole river",
              "land","Yes it is, thank god"
              });

replace_program("room/room");

}
/*filler room to extend mud far to the south*/

