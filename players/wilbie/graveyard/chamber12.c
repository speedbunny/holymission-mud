inherit"room/room";
#include "/players/wilbie/def.h"
object monst;
reset (arg){
  if (!arg){
  set_light(1);
  short_desc="The upper sanctum";
  long_desc=
  "You are in the center of the large upper sanctum of the cathedral. "+
  "All around are "+
  "fanatical looking women.  They are all in fervant prayer to some dark "+
  "power, and most of them don't even seem to notice you here.\n";

  items=({"women","They are the worshippers of this cathedral",
  "cathedral","You are in the sanctum of the cathdral",
  "sanctum","It is a place for prayer",
        });

   dest_dir=({
   GPATH+"chamber1","north",
   GPATH+"chamber2","northeast",
   GPATH+"chamber3","east",
   GPATH+"chamber4","southeast",
   GPATH+"chamber11","south",
   GPATH+"chamber13","west",
   GPATH+"chamber16","northwest",
  });
 }
::reset(arg); replace_program("/room/room");
}
