inherit "/players/brainsprain/goldsun/7-islands/rooms/cgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 ::reset(arg);

 dest_dir=({ 
    ir+"/creta15","north",
    ir+"/creta12","west",
    ir+"/creta13","southwest",
    ir+"/creta17","northeast"
           });
  
}
