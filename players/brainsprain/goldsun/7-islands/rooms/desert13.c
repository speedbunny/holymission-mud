inherit "/players/brainsprain/goldsun/7-islands/rooms/genDesert";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
if (!arg){
 set_type("sandy");
 set_name("Topaz");
 set_storm(5,13);  /* chance, storm_time */

 items=({"topaz",long_desc
         });

 dest_dir=({
     ir+"/desert15","northeast",
     ir+"/desert14","east",
     ir+"/desert10","southeast",
     ir+"/desert11", "south",
     ir+"/desert12","southwest"
           });
}
 ::reset(arg);  
}

