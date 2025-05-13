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
  "walls","They are rusty walls of iron",
  "floor","A bloodstained iron floor",
  "metal","It looks like old iron",
  "blood","It is relatively old",
  "bloodstain","It is an old stain",
  "bloodstains","They look old",
  "iron","It is very old looking",
  });

  clone_list=({
  1,1,"fanatic","/players/wilbie/graveyard/monsters/fanatic",0,
 -1,1,"mace","/players/wilbie/graveyard/weapons/mace",0,
 -1,1,"armour","/players/wilbie/graveyard/armor/armor2",0,
  });
  ::reset();
   dest_dir=({
   GPATH+"longhall6","west",

   GPATH+"longhall4","east",
   });
  }
::reset(arg); replace_program("/room/room");
 }
