   inherit"/room/room";
#include "/players/wilbie/def.h"
   reset(arg){
   if(!arg){
   set_light(0);
   short_desc="In a narrow passage";
   long_desc=
   "You find yourself in a narrow and rather low passageway.  There is "+
   "a disturbing moan coming from the north.  Demonic laughter can also "+
   "be heard, along with the occasional scream of mortal agony.\n";

  items=({
  "floor","Granite floor",
  "walls","Granite walls",
  "passageway","A granite passageway",
  "granite","A black rock",
  });
   dest_dir=({
    GPATH+"w_pass6","north",
    GPATH+"w_pass4","southeast",
    });
  }
::reset(arg); replace_program("/room/room");
 }
