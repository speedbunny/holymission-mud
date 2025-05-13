inherit"room/room";
#include "/players/wilbie/def.h"
/*Wilbie*/
object monst;

reset(arg){

   if(!arg){

   set_light(1);

   short_desc="Inside an ancient church";

   long_desc="You stand at the southern end of a huge open cathedral.  The "+
             "walls and floor are the same dark, cold granite, and huge "+
             "black pillars bear the weight of a massive stone ceiling.  "+
             "To the south is a dark hallway, and to the north you can "+
             "see a massive stone idol.\n";


   items=({"walls","They are ancient walls of granite",
           "idol","You are too far away to see details..",
           "pillars","They are of black polished granite",
           "end","This is the outhern end of the cathedral",
           "hallway","It is too dark to see down there",
           "ceiling","It is made of dark granite",
           "floor","It is made of granite",
           "granite","A cold, dark rock",
           "stone","It is granite",
           "hallway","It is too dark to see very far..",
             });

    dest_dir=({
               GPATH+"hall4","south",
               GPATH+"w_nave1","west",
                GPATH+"e_nave1","east",
               GPATH+"nave2","north",
       });
   }
::reset(arg); replace_program("/room/room");
 }
