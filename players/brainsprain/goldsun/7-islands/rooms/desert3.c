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
     ir+"/desert11","north",
     ir+"/desert10","northeast",
     ir+"/desert4","east",
     ir+"/desert2", "west",
     ir+"/desert12","northwest"
	   });
}
 ::reset(arg);  
}

