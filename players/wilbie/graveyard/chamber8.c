inherit"room/room";
#include "/players/wilbie/def.h"
object monst;
reset (arg){
  if (!arg){
  set_light(1);
  short_desc="The upper sanctum";
  long_desc=
  "You have come to the upper sanctum of the cathedral.  All around are "+
  "fanatical looking women.  They are all in fervant prayer to some dark "+
  "power.\n";

  items=({"women","They are the worshippers of this cathedral",
  "cathedral","You are in the sanctum of the cathedral",
  "sanctum","It is a place for prayer",
        });

 }
::reset(arg); replace_program("/room/room");
}
