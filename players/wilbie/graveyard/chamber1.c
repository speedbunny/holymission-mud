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

  dest_dir=({
      GPATH+"up5","north",
      GPATH+"chamber16","west",
      GPATH+"chamber12","south",
      GPATH+"chamber2","east",
      GPATH+"chamber13","southwest",
      GPATH+"chamber3","southeast",
          });
  clone_list=({
  1,1,"priestess","/players/wilbie/graveyard/monsters/apprent",0,
 -1,1,"armour","/players/wilbie/graveyard/armor/armor1",0,
 -1,1,"hammer","/players/wilbie/graveyard/weapons/hammer",0,
  });
  ::reset();
 }
::reset(arg); replace_program("/room/room");
}
