inherit "/players/brainsprain/goldsun/7-islands/rooms/genDesert";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
if (!arg){
 clone_list=({1,1,"creature","players/goldsun/7-islands/topaz/monster/creature",0});
 set_type("sandy");
 set_name("Topaz");
 set_storm(10,11);  /* chance, storm_time */

 items=({"topaz",long_desc
         });

 dest_dir=({    
     ir+"/desert14","north",
     ir+"/desert9","northeast",
     ir+"/desert5","east",
     ir+"/desert4","south",
     ir+"/desert3","southwest",
     ir+"/desert11", "west",
     ir+"/desert13","northwest"
          });

}
 ::reset(arg);  
}

