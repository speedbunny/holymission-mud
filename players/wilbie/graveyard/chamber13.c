inherit"room/room";
#include "/players/wilbie/def.h"
object monst;
reset (arg){
  if (!arg){
  set_light(1);
  short_desc="The upper sanctum";
  long_desc=
  "You are in the upper sanctum of the cathedral.  To the west there is "+
  "a dark hallway leading somewhere.  The praying sounds louder in there "+
  "but it sounds like a single voice.  All around are "+
  "fanatical looking women.  They are all in fervant prayer to some dark "+
  "power.\n";

  items=({"women","They are the worshippers of this cathedral",
  "cathedral","You are in the sanctum of the cathedral",
  "sanctum","It is a place for prayer",
        });

  dest_dir=({
  GPATH+"chamber1","northeast",
  GPATH+"chamber12","east",
  GPATH+"chamber16","north",
  GPATH+"longhall1","west",
  });
 }
::reset(arg); replace_program("/room/room");
}
