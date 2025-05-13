inherit "/players/brainsprain/goldsun/7-islands/rooms/cgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 ::reset(arg);
 long_desc=
"You are standing on the coast of Creta Island.  The ground consists of "+
"rock and sand.  Huge waves are rolling towards the island and you get "+
"a peaceful feeling. You can see a tall mountain named Idhe to the south.\n";
  
 items = ({
    "mountains","Madaros and Idhe.  They are very high"
    "mountain","the tall mountain to the south is named Idhe",
          "idhe","It is a tall mountain to the south",
          "waves","Huge waves which roll towards the island",
          "town","A town to the east"
     });

 dest_dir=({ 
    ir+"/creta8", "west",
    ir+"/creta15", "southeast",
           });
}
