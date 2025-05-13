   inherit"/room/room";
#include "/players/wilbie/def.h"
   reset(arg){
   if(!arg){
   set_light(1);
   short_desc="In a narrow passage";
   long_desc=
   "You are in a wider section of the north-south path.  There seems to have "+
   "been some violence here recently, because there is blood on the ground. "+
   "The trail seems to lead towards a large structure "+
   "of some sort.  The air smells of death.\n";

  items=({
  "trail","A trail in a dismal forest",
  "blood","It looks disturbingly fresh",
  "section","It is a little wider here",
  "ground","There is fresh blood on the ground",
  "forest","Not much you can see in the darkness",
  "structure","A large church of some sort",
  "church","It is a large black structure",
  });
  smell="You smell death.";
 
  clone_list=({
  1,1,"ghast","/players/wilbie/graveyard/monsters/ghast",0,
 -1,1,"bone","/players/wilbie/graveyard/weapons/bone",0,
 -1,1,"robe","/players/wilbie/graveyard/armor/tatt_robes",0,
  });
  ::reset();
   dest_dir=({
   GPATH+"trail5","north",

   GPATH+"trail3","south",
   });
  }
::reset(arg); replace_program("/room/room");
 }
