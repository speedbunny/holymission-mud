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

   dest_dir=({
   GPATH+"westway","west",

   GPATH+"eastway","east",
   });
  }
 }
