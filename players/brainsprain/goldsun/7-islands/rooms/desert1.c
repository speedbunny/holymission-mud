inherit "/players/brainsprain/goldsun/7-islands/rooms/genDesert";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 clone_list=({
   1,1,"sandworm",im+"/sandworm",0,
   2,4,"native",im+"/native",0,
   });
 set_type("sandy");
 set_name("Topaz");
 set_storm(7,12);  /* chance, storm_time */

 items=({"topaz",long_desc
         });

 dest_dir=({
    ir+"/desert12","northeast",
    ir+"/desert2","east",
    ir+"/coast1", "south"
           });
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
