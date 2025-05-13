   inherit"/room/room";
#include "/players/wilbie/def.h"
   reset(arg){
   if(!arg){
   set_light(0);
   short_desc="In a narrow passage";
   long_desc=
   "You are in a long hallway of white marble.  This place is very different "+
   "from the black granite of the lower floor of the cathedral.  You almost "+
  "feel safe.  But not nearly as much as a few moments ago!!.\n";

  items=({
  "marble","White polished marble",
  "hallway","A dark, quiet hallway",
  "place","You are in a marble hallway",
  "granite","You saw some granite downstairs",
  "cathedral","All you can see of the cathedral is this hallway",
  "walls","They are white marble",
  "floor","A nice, clean marble floor",
  });
   dest_dir=({
   GPATH+"up2","east",
   GPATH+"up4","west",
   });
  }
::reset(arg); replace_program("/room/room");
 }
