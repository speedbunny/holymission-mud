inherit"room/room";
#include "/players/wilbie/def.h"
reset (arg){
  if (!arg){
  set_light(1);

  short_desc="The upper sanctum";
  long_desc=
  "You are at the southern end of the upper sanctum of the cathedral. "+
  "Standing all around you are "+
  "fanatical looking women.  They are all in fervant prayer to some dark "+
  "power.\n";

  items=({"women","They are the worshippers of this cathedral",
  "cathedral","You are in the sanctum of the cathedral",
  "sanctum","It is a place for prayer",
        });

   dest_dir=({
   GPATH+"chamber4","east",
   GPATH+"chamber5","southeast",
   GPATH+"chamber6","south",
   GPATH+"chamber3","northeast",
   GPATH+"chamber13","northwest",
    GPATH+"chamber12","north",
   });
  clone_list=({
  1,1,"fanatic","/players/wilbie/graveyard/monsters/fanatic",0,
  1,2,"apprentice","/players/wilbie/graveyard/monsters/apprent",0,
  1,1,"novitate","/players/wilbie/graveyard/monsters/novitate",0,
 -1,1,"armour","/players/wilbie/graveyard/armor/armor2",0,
 -1,1,"hammer","/players/wilbie/graveyard/weapons/hammer",0,
  });
  ::reset();
 }
::reset(arg); replace_program("/room/room");
}
