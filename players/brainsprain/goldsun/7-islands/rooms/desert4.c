inherit "/players/brainsprain/goldsun/7-islands/rooms/genDesert";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
if (!arg){
 set_type("sandy");
 set_name("Topaz");
 set_storm(10,12);  /* chance, storm_time */

 items=({"topaz",long_desc
         });

 dest_dir=({
     ir+"/desert10","north",
     ir+"/desert5","northeast",
     ir+"/coast4", "south",
     ir+"/desert3","west"
           });
}
 ::reset(arg);  
}

init(){
 ::init();
 add_action("down","south");
}


down(){
 write("   ***** You are F A A *********\n\n");
 write("   ***** A A A A A A A *********\n\n");
 write("   ***** a a a a a a a *********\n\n");
 write("   ***** a a a l i n g *********\n\n");
 return ::move("south");
}
