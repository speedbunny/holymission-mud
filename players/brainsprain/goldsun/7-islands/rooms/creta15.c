inherit "/players/brainsprain/goldsun/7-islands/rooms/cgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 ::reset(arg);
  

 items = ({
     "mountains","Madaros and Idhe. They are very high",
     "mountain","there is a tall mountain to the west named Idhe",
     "idhe","It is a tall mountain to the west"
    });

 dest_dir=({ 
     ir+"/creta11","northwest",
     ir+"/creta16","south",
     ir+"/creta17","east"
           });
  
}
