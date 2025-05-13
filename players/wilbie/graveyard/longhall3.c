   inherit"/room/room";
#include "/players/wilbie/def.h"
   reset(arg){
   if(!arg){
   set_light(0);
   short_desc="In a narrow passage";
   long_desc=
   "You are in a dark hallway.  The walls seem to be made of a strange "+
   "metal, rusted from centuries of damp air.  To the west, you hear loud "+
  "chanting, almost deafening.\n";

  items=({
  "hallway","A long dark hall of iron",
  "iron","It is old, rusty iron",
  "metal","It looks like iron",
  "walls","They appear to be made of iron",
  "air","You stare blankly at the air for a moment, but fail to see it",
  "floor","There is blood stained on the iron floor here",
  });
  
  clone_list=({
  1,2,"fanatic","/players/wilbie/graveyard/monsters/fanatic",0,
  1,2,"novitate","/players/wilbie/graveyard/monsters/novitate",0,
 -1,1,"hammer","/players/wilbie/graveyard/weapons/hammer",0,
 -1,1,"armour","/players/wilbie/graveyard/armor/armor3",0,
  });
  ::reset();

   dest_dir=({
   GPATH+"longhall4","west",

   GPATH+"longhall2","east",
   });
  }
::reset(arg); replace_program("/room/room");
 }
