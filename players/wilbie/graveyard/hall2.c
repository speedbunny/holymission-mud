inherit"room/room";
#include "/players/wilbie/def.h"
/*Wilbie*/

reset(arg){

   if(!arg){

   set_light(1);

   short_desc="Within the ancient halls";


   long_desc="There is an oppressive darkness in this ancient hallway that "+
             "seems to weigh down on you from all sides.  Strange looking "+
             "torches glow on either side with an eerie, dim light.  The "+
             "walls and floor are made of ancient granite, which seems to "+
             "dampen what little light is present.  There is a feeling of "+
             "great evil in this place.  To the south and north you see "+
             "darkness.\n";
   items=({"walls","They are ancient granite walls",
           "torches","They seem to glow with some arcane magic.",
           "light","An eerie, dim light from a small flame",
           "walls","Ancient granite",
           "floor","Ancient granite",
           "darkness","You can't see anything!"});

   dest_dir=({ GPATH+"hall1","south",
               GPATH+"hall3","north",

            });
   }
  ::reset(arg); replace_program("/room/room");
 }
