   inherit"/room/room";
#include "/players/wilbie/def.h"
   reset(arg){
   if(!arg){
   set_light(0);
   short_desc="In a narrow passage";
   long_desc=
   "You are in a long, dark hallway.  The walls seem to be made out of "+
   "some strange kind of "+
   "metal, rusted from centuries of damp air.  To the west, you hear loud "+
  "chanting, almost deafening.\n";

  items=({
  "walls","They are iron walls",
  "floor","The floor is bloodstained iron",
  "iron","It is rusted from years of dampness",
  "metal","It looks like iron",
  "air","It looks just like the air everywhere else.  Like nothing",
  "blood","It looks rather old",
  "bloodstains","They look old",
  "bloodstain","It looks old",
  "hallway","It is a long iron hallway",
  });

   dest_dir=({
   GPATH+"longhall7","west",

   GPATH+"longhall5","east",
   });
  }
::reset(arg); replace_program("/room/room");
 }
