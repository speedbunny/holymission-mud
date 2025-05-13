   inherit"/room/room";
#include "/players/wilbie/def.h"
   reset(arg){
   if(!arg){
   set_light(0);

   short_desc="In a narrow passage";
   long_desc=
   "You find yourself in a narrow and rather low passageway.  There is "+
   "a whimpering cry for help coming from the west, and occasionally demonic "+
   "laughter echoes from that direction.\n";

  items=({
  "passageway","A long, granite passageway",
  "floor","A granite floor",
  "walls","Plain granite walls",
  "granite","A black type of rock",
  });
   dest_dir=({
    GPATH+"w_pass5","northwest",
    GPATH+"w_pass1","east",
   });
  clone_list=({
  1,2,"knight","/players/wilbie/graveyard/monsters/skel_knight",0,
 -1,1,"armour","/players/wilbie/graveyard/armor/skel_armor",0,
 -1,1,"axe","/players/wilbie/graveyard/weapons/skel_axe",0,
  });
  ::reset();
  }
::reset(arg); replace_program("/room/room");
 }
