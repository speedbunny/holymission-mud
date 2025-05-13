   inherit"/room/room";
#include "/players/wilbie/def.h"
   reset(arg){
   if(!arg){
   set_light(1);
   short_desc="Around the house";
   long_desc=
   "The path goes around the house, into a dark and dismal looking forest.  "+
   "To the northwest, the path continues into the darkness, and to the "+
   "southeast is the front of the house.  A strange smell lingers from "+
   "the northwest.\n";

  items=({
  "trail","An old looking trail leading into a dark forest",
  "forest","Very dark and overgrown",
  "air","It looks just like any other air that you've seen",
  "house","It looks like the house of a wicked witch",
  });
  smell="It smells like dead things";
   dest_dir=({
   GPATH+"trail2","northwest",

   GPATH+"southway","south",
   });
  }
::reset(arg); replace_program("/room/room");
 }
