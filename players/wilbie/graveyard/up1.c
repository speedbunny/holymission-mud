   inherit"/room/room";
#include "/players/wilbie/def.h"
   reset(arg){
   if(!arg){
   set_light(0);
   short_desc="In a narrow passage";
   long_desc=
   "You find yourself at the top of a spiral staircase.  A long corridor "+
   "leads off to the west.  Strange murmurs of prayer seem to come from "+
   "that direction.\n";

  items=({"staircase","It leads downward into darkness",
  "room","It is the top of a spiral staircase",
  "spiral","A very elegant spiral",
          "corridor","A very dark, very quiet corridor",
  });
   dest_dir=({
   GPATH+"up2","west",
   GPATH+"e_pass1","down",
   });
  }
::reset(arg); replace_program("/room/room");
 }
