inherit"room/room";
#include "/players/wilbie/def.h"
reset (arg){
  if (!arg){
  set_light(0);
  short_desc="The upper sanctum";
  long_desc=
  "You are at the eastern end of the upper sanctum.  All around are "+
  "fanatical looking women.  They are all in fervant prayer to some dark "+
  "power.\n";

  items=({"women","They are the worshippers of this cathedral",
  "cathedral","You are in the sanctum of the cathedral",
  "sanctum","It is a place of prayer",
        });

   dest_dir=({
   GPATH+"chamber1","northwest",
   GPATH+"chamber2","north",
   GPATH+"chamber4","south",
   GPATH+"chamber12","west",
   GPATH+"chamber11","southwest",
   });
  clone_list=({
  1,2,"fanatic","/players/wilbie/graveyard/monsters/fanatic",0,
  1,1,"novitate","/players/wilbie/graveyard/monsters/novitate",0,
 -1,1,"flail","/players/wilbie/graveyard/weapons/flail",0,
 -1,1,"armour","/players/wilbie/graveyard/armor/armor2",0,
  });
  ::reset();
 }
::reset(arg); replace_program("/room/room");
}
