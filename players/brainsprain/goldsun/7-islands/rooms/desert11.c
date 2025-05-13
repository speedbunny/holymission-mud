inherit "/players/brainsprain/goldsun/7-islands/rooms/genDesert";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
if (!arg){
 clone_list=({1,1,"vulture","players/goldsun/7-islands/topaz/monster/vulture",0});
 set_type("sandy");
 set_name("Topaz");
 set_storm(10,12);  /* chance, storm_time */

 items=({"topaz",long_desc
         });

 dest_dir=({    
     ir+"/desert13","north",
     ir+"/desert14","northeast",
     ir+"/desert10","east",
     ir+"/desert4","southeast",
     ir+"/desert3","south",
     ir+"/desert2", "southwest",
     ir+"/desert12","west"
           }); 
}
 ::reset(arg);  
}

