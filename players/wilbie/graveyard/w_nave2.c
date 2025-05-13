inherit"room/room";
#include "/players/wilbie/def.h"
/*Wilbie*/

reset(arg){

   if(!arg){

   set_light(1);

   short_desc="Western side of an ancient church";


  long_desc="You stand at the western wall in a huge cathedral.  A really "+
            "huge stained glass window dominates the eastern wall.  The "+
            "air seems oddly cold here.  To the north, you see a huge stone "+
            "idol.\n";

   items=({"walls","They are ancient walls of granite",
           "idol","You are too far away to see details",
           "pillars","They are of black polished granite",
           "window","It depicts a wizard of great power destroying a town",
           "air","You squint really hard and try to look at the air, "+
                 "but all you really find is a headache",
           "cathedral","It's a pretty big place",
           "glass","It is remarkably clean for such an old place",
           "hallway","It is too dark to see that far",
           "wall","It is a granite wall",
             });

    dest_dir=({
                GPATH+"nave2","east",
                GPATH+"w_nave1","south",
                GPATH+"w_nave3","north",
       });

  clone_list=({
  1,1,"skeleton","/players/wilbie/graveyard/monsters/skel_warr",0,
 -1,1,"axe","/players/wilbie/graveyard/weapons/skel_axe",0,
 -1,1,"armour","/players/wilbie/graveyard/armor/skel_armor",0,
  });
  ::reset();
   }
::reset(arg); replace_program("/room/room");
 }
