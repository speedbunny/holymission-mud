inherit"room/room";
#include "/players/wilbie/def.h"
reset (arg){
  if (!arg){
  set_light(1);
  short_desc="The upper sanctum";
  long_desc=
  "You have come to the upper sanctum of the cathedral.  All around are "+
  "fanatical looking women.  They are all in fervant prayer to some dark "+
  "power.\n";

  items=({"women","They are the worshippers of this cathedral",
          "sanctum","A large room for worshipping in",
   "cathedral","You are in the sanctum of the cathedral",
        });

  clone_list=({
  1,1,"priestess","/players/wilbie/graveyard/monsters/testpr",0,
 -1,1,"mace","/players/wilbie/graveyard/weapons/mace",0,
  });
  ::reset();
 }
replace_program("/room/room");
}
