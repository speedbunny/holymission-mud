inherit"room/room";
#include "/players/wilbie/def.h"
/*Wilbie*/

reset(arg){

   if(!arg){

   set_light(1);

   short_desc="Eastern side of an ancient church";


  long_desc="You stand at the southern side in a huge cathedral.  A really "+
            "huge stained glass window dominates the eastern wall.  The "+
            "air seems oddly cold here.  To the north, you see a huge stone "+
            "idol.\n";

   items=({"walls","They are ancient walls of granite",
           "idol","You are too far away to see details..",
           "pillars","They are of black polished granite",
           "hallway","It is too dark to see very far..",
           "window","It depicts a wizard of great power destroying a town...",
           "stone","Ancient black granite",
           "wall","A granite wall",
          
             });

    dest_dir=({
               GPATH+"nave2","west",
               GPATH+"e_nave1","south",
               GPATH+"e_nave3","north",
       });
  clone_list=({
  1,1,"skeleton","/players/wilbie/graveyard/monsters/skel_warr",0,
 -1,1,"sword","/players/wilbie/graveyard/weapons/skel_sword",0,
 -1,1,"armour","/players/wilbie/graveyard/armor/skel_armor",0,
  });
  ::reset();
   }
::reset(arg); replace_program("/room/room");
 }
