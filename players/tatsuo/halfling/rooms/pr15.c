inherit "room/room";
#include "/players/tatsuo/def.h"

void reset(int arg){


}

if(arg) return;

  set_light(1);

  long_desc = "A wide wooden bridge spans the river to the east.  The river "+
              "path intersects with a dirt road running west to east.  The "+
              "path to the south stop abrutptly at the intersection"+
   
            
              ".\n";

  short_desc= "Along the Shayla river";

  dest_dir = ({ HPATH+"pr14","north", /*HPATH+"bridge2","east"*/ });

  items = ({  "valley","Umm, the valley is to the north",
              "stone structure","go south and see for yourself",
              "structure","It lies to the south",
              "river","Same ole river",
              "land","Yes it is, thank god"
              });

replace_program("room/room");

}
/*filler room to extend mud far to the south*/

