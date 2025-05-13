   inherit"/room/room";
#include "/players/wilbie/def.h"
   reset(arg){
   if(!arg){
   set_light(0);
   short_desc="In a narrow passage";
   long_desc=
   "You are in a long, dark hallway that runs east to west.  There is "+
  "a very loud "+
   "metal, rusted from centuries of damp air.  To the west, you hear loud "+
  "chanting, almost deafening.\n";

  items=({
  "walls","They are made of rusty iron",
  "floor","It is made of rusty iron",
  "hallway","A long dark hall of iron",
  "iron","It is rusted from the years",
  "air","You don't see anything special about the air",
  "metal","It is iron",
  });
  
  clone_list=({
  1,2,"fanatic","/players/wilbie/graveyard/monsters/fanatic",0,
 -1,1,"flail","/players/wilbie/graveyard/weapons/flail",0,
 -1,1,"armour","/players/wilbie/graveyard/armor/armor3",0,
  });
  ::reset();
   dest_dir=({
   GPATH+"longhall3","west",

   GPATH+"longhall1","east",
   });
  }
::reset(arg); replace_program("/room/room");
 }
