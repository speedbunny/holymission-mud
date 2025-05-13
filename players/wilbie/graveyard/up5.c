   inherit"/room/room";
#include "/players/wilbie/def.h"
   reset(arg){
   if(!arg){
   set_light(0);
   short_desc="In a narrow passage";
   long_desc=
   "The hallway continues north and south here, and there is a slight "+
   "chill coming from the "+
   "south.  The slight feeling of ease has been replaced by fear.  The "+
   "silence of this place is broken only by your rapid heartbeat.\n";

  items=({
  "hallway","A long, dark hallway of marble",
  "marble","A white rock used for building",
  "floor","A nice marble floor",
  "chill","You can't see the chill",
  "place","The long hallway of marble",
  "walls","Nice marble walls",
  });
   dest_dir=({
   GPATH+"up4","north",
   GPATH+"chamber1","south",
   });
  }
::reset(arg); replace_program("/room/room");
 }
