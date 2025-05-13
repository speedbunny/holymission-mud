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
  "hallway","A dark hallway seemingly made out of metal",
  "metal","It looks like rusty iron",
  "iron","It must be very old",
  "rust","It would have taken decades for iron to rust so much",
  "air","Looking at the air gives you time to think about the meaning "+
        "of life.  You don't come up with any answers, but you feel "+
        "somehow refreshed by the contemplation",
  "walls","They are rusted iron walls",
  "floor","A rusted iron floor",
  });
   dest_dir=({
   GPATH+"chamber13","east",
   GPATH+"longhall2","west",
   });
  }
::reset(arg); replace_program("/room/room");
 }
