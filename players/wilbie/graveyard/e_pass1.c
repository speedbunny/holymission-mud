   inherit"/room/room";
#include "/players/wilbie/def.h"
   reset(arg){
   if(!arg){
   set_light(0);
   short_desc="In a narrow passage";
   long_desc=
   "You are at the bottom of a large spiral staircase rising upwards "+
   "into the darkness.  To the west is the nave of the cathedral.\n";

  items=({
  "corridor","It is a dark corridor leading to a spiral staircase",
  "staircase","It leads upward",
  "room","It holds a spiral staircase",
  });

  clone_list=({
  1,1,"knight","/players/wilbie/graveyard/monsters/skel_knight",
  ({ "set_level" , 18 }),
 -1,1,"sword","/players/wilbie/graveyard/weapons/msword",0,
 -1,1,"armour","/players/wilbie/graveyard/armor/armor1",0,
  });
  ::reset();
   dest_dir=({
   GPATH+"e_nave3","west",
   "/players/wilbie/barriers/up1","up",
   });
  }
::reset(arg); replace_program("/room/room");
 }
