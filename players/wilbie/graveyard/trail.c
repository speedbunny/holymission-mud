   inherit"/room/room";
#include "/players/wilbie/def.h"
   reset(arg){
   if(!arg){
   set_light(1);
   short_desc="In a narrow passage";
   long_desc=
   "You are on a north-south trail.  To the north you see a large structure "+
   "of some sort.  The air smells of death.\n";

   dest_dir=({
   GPATH+"northway","north",

   GPATH+"southway","south",
   });
  }
 }
