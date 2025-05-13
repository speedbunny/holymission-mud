inherit "/players/brainsprain/goldsun/7-islands/rooms/cgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 ::reset(arg);
 long_desc=
"You are standing on the coastline of Creta Island.  The ground consists "+
"of rock and sand. Huge waves are rolling towards the island and you get "+
"a peaceful feeling.  Far inland you can see tall mountains.  The coast "+
"runs past white cliffs to the north.\n";

 items =({ 
   "cliff","A cliff to the north"
 });
 dest_dir=({ 
  ir+"/creta20", "north",
  ir+"/creta18", "southwest"
           });
}
