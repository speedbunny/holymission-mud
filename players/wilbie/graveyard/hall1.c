inherit"room/room";
#include "/players/wilbie/def.h"

reset(arg){

   if(!arg){

   set_light(1);

   short_desc="Within the ancient halls";


   long_desc="There is an oppressive darkness in this ancient hallway that "+
             "seems to weigh down on you from all sides.  Strange looking "+
             "torches glow on either side with an eerie, dim light.  The "+
             "walls and floor are made of ancient granite, which seems to "+
             "absorb what little light is present.  To the south you see the "+
             "dim glow of moonlight, and to the north there is utter "+
             "darkness.\n";
   items=({"walls","They are ancient granite walls",
           "torches","They seem to glow with some arcane magic.",
           "darkness","You can't see anything"});
           "light","The light is that of a dim flame",
           "floor","The floor is granite like the walls",
           "granite","It is a hard, dark type of rock",
           "north","You can't see that far in the darkness",
           "south","You see the moonlight",
           "moonlight","Dim and spooky",

   dest_dir=({ "/players/wilbie/barriers/entrance","south",
               GPATH+"hall2","north",
            });
   }
  ::reset(arg); replace_program("/room/room");
 }
