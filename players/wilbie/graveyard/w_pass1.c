   inherit"/room/room";
#include "/players/wilbie/def.h"
   reset(arg){
   if(!arg){
   set_light(0);
   short_desc="In a narrow passage";
   long_desc=
   "You find yourself in a narrow and rather low passageway.  There is "+
   "a disturbing moan coming from the west, and occasionally demonic "+
   "sounding laughter.\n";

  items=({
  "passageway","A long dark passageway",
  "walls","They are granite",
  "floor","It is granite",
  });
   dest_dir=({
   GPATH+"w_pass4","west",
   GPATH+"w_nave3","east",
   });
  }
::reset(arg); replace_program("/room/room");
 }
