inherit"room/room";
#include "/players/wilbie/def.h"
/*Wilbie*/
object monst;

reset(arg){

   if(!arg){

   set_light(1);

   short_desc="Eastern side of an ancient church";


  long_desc="You stand in the southeastern corner of a huge cathedral.  A "+
            "huge stained glass window dominates the eastern wall.  The "+
            "air seems oddly cold here.  To the north, you see a huge stone "+
            "idol.\n";

   items=({"walls","They are ancient walls of granite",
           "idol","You are too far away to see details",
           "pillars","They are of black polished granite",
           "hallway","It is too dark to see very far",
           "window","It depicts a huge skeletal dragon destroying a village",
           "cathedral","The southeastern corner of a large cathedral",
             });

    dest_dir=({
               GPATH+"nave1","west",
               GPATH+"e_nave2","north",
       });
   }
::reset(arg); replace_program("/room/room");
 }
