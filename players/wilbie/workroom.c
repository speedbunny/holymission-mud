inherit"room/room";
#include "/players/wilbie/def.h"
#include "/players/wilbie/break_str.h"
object monst;

reset(arg){

   if(!arg){

   set_light(1);

   short_desc="Within the ancient halls";


   long_desc="There is an oppressive darkness in this room that "+
             "seems to weigh down on you from all sides.  Strange looking "+
             "torches glow on either side with an eerie, dim light.  The "+
             "walls and floor are made of ancient granite, which seems to "+
             "dampen what little light is present.  There is a feeling of "+
             "great evil in this place.  All around you see "+
             "darkness.\n";
   items=({"walls","They are ancient granite walls.",
           "torches","They seem to glow with some arcane magic...",
           "darkness","You can't see anything!"});




   }
 }
