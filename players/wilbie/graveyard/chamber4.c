inherit"room/room";
#include "/players/wilbie/def.h"
object monst;
reset (arg){
  if (!arg){
  set_light(0);
  short_desc="The upper sanctum";
  long_desc=
  "You are at the southern end of the upper sanctum.  All around are "+
  "fanatical looking women.  They are all in fervant prayer to some dark "+
  "power.\n";

  items=({"women","They are the worshippers of this cathedral",
  "cathedral","You are in the sanctum of the cathedral",
  "sanctum","It is a place for paryer",
        });

 dest_dir=({
  GPATH+"chamber3","north",
  GPATH+"chamber5","south",
  GPATH+"chamber6","southwest",
  GPATH+"chamber11","west",
  GPATH+"chamber12","northwest",
  });
 }
::reset(arg); replace_program("/room/room");
}
