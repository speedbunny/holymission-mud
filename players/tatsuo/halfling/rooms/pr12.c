inherit "room/room";
#include "/players/tatsuo/def.h"

void reset(int arg){


}

if(arg) return;

  set_light(1);

  long_desc = "You can make out stone structure jutting into the sky a little further "+
              "to the south.  The path continues along the river"+
              ".\n";

  short_desc= "Along the Shayla river";

  dest_dir = ({ HPATH+"pr11","north", HPATH+"pr13","south" });

  items = ({  "valley","Umm, the valley is to the north",
              "stone structure","go south and see for yourself",
              "structure","It lies to the south",
              "river","Same ole river",
              "land","Yes it is, thank god"
              });

replace_program("room/room");

}
/*filler room to extend mud far to the south*/

