inherit "/players/brainsprain/goldsun/7-islands/rooms/rgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
{
 
 if (!arg)
 {
  
  dest_dir=({ 
    ir+"/pass", "northwest",
    ir+"/inland1","north",
    ir+"/ridge10","southeast"
            });
	    

 }
 ::reset(arg);
}
