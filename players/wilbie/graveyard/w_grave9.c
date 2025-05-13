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
   "grove","A dark grove of trees",
   "trees","Dismal looking trees",
   "structure","You can barely see it",
           "graveyard","It is old and in ill-repair"});
   dest_dir=({
   GPATH+"w_grave8", "north",
   GPATH+"w_grave4", "east",
   });

 }
::reset(arg); replace_program("/room/room");
 }
