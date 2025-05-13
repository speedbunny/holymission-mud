   inherit"/room/room";
#include "/players/wilbie/def.h"
   reset(arg){
   if(!arg){
   set_light(0);
   short_desc="In a narrow passage";
   long_desc=
   "You are in a dark hallway.  The walls seem to be made of a strange "+
   "metal, rusted from centuries of damp air.  To the west, you hear loud "+
  "chanting that sounds like it's very, very close.\n";

  items=({
  "walls","They are iron",
  "iron","Rusty iron",
  "metal","Rusty iron",
  "floor","An iron floor",
  "air","The air here has a slightly higher concentration of sulfur than "+
        "the usual Holy Mission air",
  "hallway","A dark iron hallway",
  });
   dest_dir=({
   GPATH+"longhall9","west",

   GPATH+"longhall7","east",
   });
  }
::reset(arg); replace_program("/room/room");
 }
