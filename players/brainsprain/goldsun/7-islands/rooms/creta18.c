inherit "/players/brainsprain/goldsun/7-islands/rooms/cgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 ::reset(arg);
 
 dest_dir=({ 
  ir+"/creta19", "northeast",
  ir+"/creta17", "west"
           });
  
}
