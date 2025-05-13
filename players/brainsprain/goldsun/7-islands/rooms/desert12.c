inherit "/players/brainsprain/goldsun/7-islands/rooms/genDesert";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
if (!arg){
 clone_list=({1,1,"creature","players/goldsun/7-islands/topaz/monster/creature",0});
 set_type("sandy");
 set_name("Topaz");
 set_storm(7,12);  /* chance, storm_time */

 items=({"topaz",long_desc
         });

 dest_dir=({    
     ir+"/desert13","northeast",
     ir+"/desert11","east",
     ir+"/desert3","southeast",
     ir+"/desert2", "south",
     ir+"/desert1","southwest"
           });
}
 ::reset(arg);  
}

