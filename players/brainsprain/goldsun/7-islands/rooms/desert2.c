inherit "/players/brainsprain/goldsun/7-islands/rooms/genDesert";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
if (!arg){
 clone_list=({
   1,2,"native",im+"/native",0
  });
 set_type("sandy");
 set_name("Topaz");
 set_storm(8,12); 
 items=({"topaz",long_desc
         });
dest_dir=({   
                ir+"/desert12","north",
                ir+"/desert11","northeast",
                ir+"/desert3", "east",
                ir+"/desert1","west"
           });
 ::reset(arg);  
}
}

