inherit "/players/brainsprain/goldsun/7-islands/rooms/genDesert";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
if (!arg){
clone_list=({
     1,3,"vulture",im+"/vulture",0,
     2,1,"creature",im+"/creature",0
});

 set_type("sandy");
 set_name("Topaz");
 set_storm(9,17);  /* chance, storm_time */

 items=({"topaz",long_desc
         });

dest_dir=({    
     ir+"/desert8","north",
     ir+"/desert7","northeast",
     ir+"/desert6","east",
     ir+"/desert5","south",
     ir+"/desert10","southwest",
     ir+"/desert14", "west",
     ir+"/desert15","northwest"
           });
}
 ::reset(arg);  
}
