inherit "room/room";
#include "/players/tatsuo/def.h"

void reset(int arg){

if(!present("fisherman")){
MO(CO(HMON+"fisherman"),TO);
MO(CO(HMON+"fisherman"),TO);
MO(CO(HMON+"fisherman"),TO);
MO(CO(HMON+"fisherman"),TO);
MO(CO(HMON+"hchild"),TO);
}

if(arg) return;

  set_light(1);

  long_desc = "You are standing on a narrow wooden bridge that spans the Shayla "+
              "River.  The halflings have established a village on both sides "+
              "of the river.  It is common to see a halfling fishing from the "+
              "bridge"+
   
            
              ".\n";

  short_desc= "Along the Shayla river";

  dest_dir = ({ HPATH+"p6","east", HPATH+"p12","west" });

  items = ({  "valley","Umm, the valley is to the north",
              "stone structure","go south and see for yourself",
              "structure","It lies to the south",
              "river","Same ole river",
              "land","Yes it is, thank god"
              });

replace_program("room/room");

}
/*filler room to extend mud far to the south*/

