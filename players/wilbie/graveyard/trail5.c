   inherit"/room/room";
#include "/players/wilbie/def.h"
   reset(arg){
   if(!arg){
   set_light(1);
   short_desc="In a narrow passage";
   long_desc=
   "You are on a north-south trail.  To the north you see a large structure "+
   "surrounded by a graveyard.  The air smells of death.\n";

  items=({
  "trail","A trail in the dismal forest",
  "forest","A very dark, dismal place",
  "structure","A large structure",
  "church","You are still too far away",
  "graveyard","It looks like a very old graveyard",
  });
  smell="You smell death in the air.";

   dest_dir=({
   GPATH+"e_grave12","north",

   GPATH+"trail4","south",
   });
  }
::reset(arg); replace_program("/room/room");
 }
