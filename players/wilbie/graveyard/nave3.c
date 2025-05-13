inherit"room/room";
#include "/players/wilbie/def.h"
/*Wilbie*/
object monst;

reset(arg){

   if(!arg){

   set_light(1);

   short_desc="Before the idol";
   long_desc="You stand before the altar of this ancient cathedral.  Behind "+
             "the altar stands a massive stone idol.  There are great black "+
             "tapestries all around the altar and idol, which bear runes "+
             "embroidered in golden thread.\n";
   items=({"walls","They are ancient walls of granite",
   "idol","It is a horrific looking figure with six arms, and has the face "+
                  "and body of a woman.  Each arm holds a black sword",
           "hallway","It is too dark to see very far",
           "tapestries","They are covered in arcane runes",
           "altar","It is old stone, with faint stains of red",
           "runes","You cannot read the runes",
           "cathedral","An ancient stone cathedral",
           "stone","Ancient granite",
           "granite","A dark rock",
           "thread","It looks like it might be real gold",
             });

    dest_dir=({
               GPATH+"nave2","south",
               GPATH+"w_nave3","west",
               GPATH+"e_nave3","east",
               GPATH+"altar1","north",
       });

clone_list=({
  1,1,"elder","/players/wilbie/graveyard/monsters/elder",0,
 -1,1,"platemail","/players/wilbie/graveyard/armor/armor2",0,
 -1,1,"helmet","/players/wilbie/graveyard/armor/helmet",0,
 -1,1,"cloak","/players/wilbie/graveyard/armor/cloak",0,
});
::reset();
   }
 }
