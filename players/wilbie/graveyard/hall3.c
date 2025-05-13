inherit"room/room";
#include "/players/wilbie/def.h"
/*Wilbie*/

reset(arg){

   if(!arg){

   set_light(0);

   short_desc="Within the ancient halls";


   long_desc="There is an oppressive darkness in this ancient hallway that "+
             "seems to weigh down on you from all sides.  Strange looking "+
             "torches sit dark on either side as if recently extinguished.  The "+
             "walls and floor are made of ancient granite, which seems to "+
             "dampen what little light is present.  There is a feeling of "+
             "great evil in this place.  To the south and north you see "+
             "darkness.\n";
   items=({"walls","They are ancient granite walls",
           "torches","They have been extinguished recently",
           "floor","Ancient granite, with a hint of what might be blood",
           "darkness","You can't see anything!"});

   dest_dir=({ GPATH+"hall2","south",
               GPATH+"hall4","north",

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
