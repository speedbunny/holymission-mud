inherit"room/room";
#include "/players/wilbie/def.h"
/*Wilbie*/

reset(arg){
   if(!arg){
   set_light(0);
   short_desc="In an ancient graveyard";
   long_desc="You stand in an ancient graveyard.  The ground is soggy and "+
             "covered with strange moss.  All around is a large "+
             "grove of trees, and there is a structure to the northeast.\n";

   items=({"moss","It is an odd color of green",
   "ground","Soggy ground",
   "grove","Dismal looking trees",
   "trees","A dismal looking grove",
   "structure","You can barely see it through the grove",
           "graveyard","It is old and in ill-repair"});
   dest_dir=({
   GPATH+"w_grave2", "east",
   GPATH+"w_grave8", "south",
   GPATH+"w_grave6", "north",
   });

 }
::reset(arg); replace_program("/room/room");
 }
