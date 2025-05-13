   inherit"/room/room";
#include "/players/wilbie/def.h"
   reset(arg){
   if(!arg){
   set_light(0);
   short_desc="In a narrow passage";
   long_desc=
   "This dark hallway is certainly long.  The walls seem to be made "+
   "of a strange "+
   "metal, rusted from centuries of damp air.  To the west, you hear loud "+
  "chanting, almost deafening.\n";

  items=({
  "walls","Iron walls with a lot of rust",
  "floor","A rusty iron floor with blood stains",
  "metal","It looks like iron",
  "iron","Rusty",
  "air","The air looks pretty damp",
  "bloodstains","It certainly is not as old as the rust",
  "blood","It is certainly not as old as the rest of this place",
  });

  clone_list=({
  1,1,"novitate","/players/wilbie/graveyard/monsters/novitate",0,
 -1,1,"shield","/players/wilbie/graveyard/armor/shield1",0,
 -1,1,"mace","/players/wilbie/graveyard/weapons/mace",0,
  });
  ::reset();

   dest_dir=({
   GPATH+"longhall8","west",

   GPATH+"longhall6","east",
   });
  }
::reset(arg); replace_program("/room/room");
 }
