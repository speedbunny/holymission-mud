inherit "/players/brainsprain/goldsun/7-islands/rooms/genDesert";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
if (!arg){
clone_list=({
     1,2,"sandworm",im+"/sandworm",0,
            2,1,"creature",im+"/creature",0}
);
 set_type("sandy");
 set_name("Topaz");
 set_storm(12,12);  /* chance, storm_time */

 items=({"topaz",long_desc
         });

 dest_dir=({
     ir+"/desert7","north",
     ir+"/desert16","northeast",
     ir+"/desert5", "southwest",
     ir+"/desert9", "west",
     ir+"/desert8","northwest"
           });
}
 ::reset(arg);  
}

