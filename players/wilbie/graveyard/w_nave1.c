inherit"room/room";
#include "/players/wilbie/def.h"
/*Wilbie*/
object monst;

reset(arg){

   if(!arg){

   set_light(1);


   short_desc="Western side of an ancient church";


  long_desc="You stand in the southwestern corner of a huge cathedral.  A "+
            "huge stained glass window dominates the western wall.  The damp "+
            "air seems oddly cold here.  To the north, you see a huge stone "+
            "idol.\n";

   items=({"walls","They are ancient walls of granite",
           "idol","You are too far away to see details",
           "air","You see some dust, and a few flying bugs",
           "corner","There is a pile of dust in the corner",
           "pile","It looks like dust",
           "dust","The dust really isn't that interesting",
           "wall","It is a large wall",
           "stone","Old stone",
           "pillars","They are of black polished granite",
           "hallway","It is too dark to see very far",
           "window","It depicts an odd looking graveyard",
             });

    dest_dir=({
                GPATH+"nave1","east",
               GPATH+"w_nave2","north",
       });
   }
::reset(arg);
 }
void init(){
::init();
add_action("touch","enter");
add_action("touch","touch");
}

int touch(string str){
    if(str=="window"){
         write("You feel a sudden shift in reality...\n");
         this_player()->move_player(" into the window...",GPATH+"window1.c");
    return 1;
    }
notify_fail("What are you trying to do?\n");
return 0;
}
