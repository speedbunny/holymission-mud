inherit "/players/brainsprain/goldsun/7-islands/rooms/genDesert";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
if (!arg){
 clone_list=({
     1,3,"creature",im+"creature",0,
            2,1,"native",im+"/native",0,
            3,1,"dragon",im+"/dragon",0
});
 set_type("sandy");
 set_name("Topaz");
 set_storm(5,21);  /* chance, storm_time */

 items=({"topaz",long_desc
         });

 dest_dir=({
     ir+"/desert8","west",
     ir+"/desert16","east",
     ir+"/desert6", "south",
     ir+"/desert9","southwest"
           });
}
 ::reset(arg);  
}
