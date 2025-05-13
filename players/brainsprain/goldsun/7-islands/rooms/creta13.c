inherit "/players/brainsprain/goldsun/7-islands/rooms/cgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 ::reset(arg);
 short_desc=("Cape Lithinon");
 long_desc=
"You are standing on the southern coast of Creta Island.  This is cape of "+
"Lithinon.  The ground consists of rock and sand.  Huge waves are rolling "+
"towards the island and you get a peaceful feeling. Far inland "+
"you can see tall mountains.\n";

 dest_dir=({
    ir+"/creta10", "northwest",
    ir+"/creta16", "northeast"
           });
  
}
