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

  long_desc = "The river path runs along the west shore of this seemingly "+
              "endless river.  It continues southward as far as the eye can see"+
              ".\n";

  short_desc= "Along the Shayla river";

  dest_dir = ({ HPATH+"pr10","north", HPATH+"pr12","south" });

  items = ({  "valley","Umm, the valley is to the north",
              "river","Same ole river",
              "land","Yes it is, thank god"
              });

replace_program("room/room");

}
/*filler room to extend mud far to the south*/

