   inherit"/room/room";
#include "/players/wilbie/def.h"
   reset(arg){
   if(!arg){
   set_light(0);
   short_desc="In a narrow passage";
   long_desc=
   "You find yourself in a narrow and rather low passageway.  There is "+
   "a feeble crying sound coming from the west, and occasionally demonic "+
   "sounding laughter.\n";

   items=({
   "passageway","A long dark passageway",
   "walls","A granite wall",
   "floor","A granite floor",
   });
   dest_dir=({
    GPATH+"w_pass3","west",
   GPATH+"w_pass1","east",
   });
  }
::reset(arg); replace_program("/room/room");
 }
