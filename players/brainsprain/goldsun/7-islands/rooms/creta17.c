inherit "/players/brainsprain/goldsun/7-islands/rooms/cgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 ::reset(arg);
 
 dest_dir=({ 
   ir+"/creta15", "west",
   ir+"/creta16", "southwest",
   ir+"/creta18", "east"
           });
  
}
