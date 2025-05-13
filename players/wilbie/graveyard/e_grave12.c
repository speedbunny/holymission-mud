inherit"room/room";
#include "/players/wilbie/def.h"
/*Wilbie*/

reset(arg){
   if(!arg){
   set_light(1);
   short_desc="In an ancient graveyard";
   long_desc="You are at the edge of an ancient graveyard.  The ground "+
   "is soggy and "+
             "covered with strange moss.  To the northwest there is a large "+
  "granite structure.  The smell of death fills the air.\n";

   items=({"moss","It is an odd color of green",
           "structure","A large church of some sort",
           "church","It is large and black",
           "ground","It is soggy and covered with moss",
           "graveyard","It is old and in ill-repair"});
   dest_dir=({
   GPATH+"e_grave10", "north",
   GPATH+"trail5","south",
   });
  smell="You smell death in the air.";

 }
::reset(arg); replace_program("/room/room");
 }
