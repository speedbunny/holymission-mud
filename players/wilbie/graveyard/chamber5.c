inherit"room/room";
#include "/players/wilbie/def.h"
reset (arg){
  if (!arg){
  set_light(0);
  short_desc="The upper sanctum";
  long_desc=
  "You have come to the upper sanctum of the cathedral.  All around are "+
  "fanatical looking women.  They are all in fervant prayer to some dark "+
  "power.\n";

  items=({"women","They are the worshippers of this cathedral",
  "cathedral","You are in the sanctum of the cathedral",
  "sanctum","It is a place for prayer",
        });

  dest_dir=({
  GPATH+"chamber4","north",
  GPATH+"chamber6","west",
  GPATH+"chamber11","northwest",
   });
  clone_list=({
  1,1,"fanatic","/players/wilbie/graveyard/monsters/fanatic",0,
 -1,1,"mace","/players/wilbie/graveyard/weapons/mace",0,
  });
  ::reset();
 }
::reset(arg); replace_program("/room/room");
}
