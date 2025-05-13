inherit "/players/brainsprain/goldsun/7-islands/rooms/genDesert";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
if (!arg){
 clone_list=({
     1,1,"sandworm",im+"/sandworm",0,
     2,1,"vulture",im+"/vulture",0
  });
 set_type("sandy");
 set_name("Topaz");
 set_storm(10,12);  /* chance, storm_time */

 items=({"topaz",long_desc
         });

 dest_dir=({
     ir+"/desert15","west",
     ir+"/desert7","east",
     ir+"/desert6","southeast",
     ir+"/desert9", "south",
     ir+"/desert14","southwest"
           });
}
 ::reset(arg);  
}
