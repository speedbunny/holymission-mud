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
     ir+"/desert9","north",
     ir+"/desert6","northeast",
     ir+"/desert4", "southwest",
     ir+"/desert10","west",
     ir+"/desert14","northwest"
           });
}
 ::reset(arg);  
}

