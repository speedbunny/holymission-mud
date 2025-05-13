inherit "/players/brainsprain/goldsun/7-islands/rooms/genDesert";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
if (!arg){
 clone_list=({
     1,3,"sandworm",im+"/sandworm",0,
     2,1,"native",im+"/native",0
});
 set_type("sandy");
 set_name("Topaz");
 set_storm(10,12);  /* chance, storm_time */

 items=({"topaz",long_desc
         });

 dest_dir=({    
     ir+"/desert8","east",
     ir+"/desert14", "south",
     ir+"/desert13","southwest"
           });
}
 ::reset(arg);  
}

