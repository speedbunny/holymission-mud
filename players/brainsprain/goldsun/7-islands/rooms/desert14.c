inherit "/players/brainsprain/goldsun/7-islands/rooms/genDesert";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
if (!arg){
 clone_list=({
     1,3,"sandworm",im+"/sandworm",0,
     2,1,"dragon",im+"/dragon",0,
     3,2,"vulture",im+"/vulture",0
     });
 set_type("sandy");
 set_name("Topaz");
 set_storm(8,12);  /* chance, storm_time */

 items=({"topaz",long_desc
         });

 dest_dir=({    
     ir+"/desert15","north",
     ir+"/desert8","northeast",
     ir+"/desert9","east",
     ir+"/desert5","southeast",
     ir+"/desert10","south",
     ir+"/desert11","southwest",
     ir+"/desert3", "west"
           });
}
 ::reset(arg);  
}

init(){
 ::init();
 add_action("enter","enter");
}


int enter(){
 write("Dune is closed now.\n");
 return 1;
}
