   inherit"/room/room";
#include "/players/wilbie/def.h"
   reset(arg){
   if(!arg){
   set_light(1);
   short_desc="In a narrow passage";
   long_desc=
   "You are on a trail running north-south through the forest.  To the north "+
   "there is a large structure "+
   "of some sort.  The air smells of death.\n";

  items=({
   "trail","It is a trail in a dismal looking forest",
   "forest","Very dark and dismal around here",
   "structure","It looks like a very large church of some kind",
   "church","You are too far away to see much",
   });
   smell="You smell dead things.";
   dest_dir=({
   GPATH+"trail4","north",

   "/players/wilbie/barriers/trail2","south",
   });
  }
::reset(arg); replace_program("/room/room");
 }
