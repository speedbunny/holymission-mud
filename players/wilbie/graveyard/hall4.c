inherit"room/room";
#include "/players/wilbie/def.h"
/*Wilbie*/

reset(arg){

   if(!arg){

   set_light(1);
   short_desc="Within the ancient halls";


   long_desc="The oppressive darkness of the hallway is lit slightly by an "+
            "eerie glow to the north, out of what seems to be a more open "+
             "area.  To the south there is only darkness, and cold walls of "+
             "ancient granite on both sides.  The odd torches are slightly "+
              "brighter here.\n";

   items=({"walls","They are ancient walls of granite",
           "torches","They seem to glow with some arcane magic..",
           "area","It looks like some sort of church",
           "glow","You cannot identify the source",
           "darkness","You can't see anything!"});

    dest_dir=({
               GPATH+"hall3","south",
               GPATH+"nave1","north",
            });
  clone_list=({
  1,2,"knight","/players/wilbie/graveyard/monsters/skel_knight",0,
 -1,1,"armour","/players/wilbie/graveyard/armor/skel_armor",0,
 -1,1,"axe","/players/wilbie/graveyard/weapons/skel_axe",0,
  });
  ::reset();
   }
::reset(arg); replace_program("/room/room");
 }
