inherit "room/room";
#include "/players/tatsuo/def.h"

void reset(int arg){

if(!present("fisherman")){
MO(CO(HMON+"fisherman"),TO);
MO(CO(HMON+"fisherman"),TO);
MO(CO(HMON+"hchild"),TO);
}

if(arg) return;

  set_light(1);

  long_desc = "The valley opens out into a large plain extending in all directions. "+
              " The river is the only feature to be seen on this vast open land"+
              ".\n";

  short_desc= "Along the Shayla river";

  dest_dir = ({ HPATH+"pr9","north", HPATH+"pr11","south" });

  items = ({  "valley","Umm, the valley is to the north",
              "river","Same ole river",
              "land","Yes it is, thank god"
              });

replace_program("room/room");

}
/*filler room to extend mud far to the south*/

