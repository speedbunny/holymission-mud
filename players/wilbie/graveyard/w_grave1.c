inherit"room/room";
#include "/players/wilbie/def.h"
/*Wilbie*/

reset(arg){
   if(!arg){
   set_light(1);
   short_desc="In an ancient graveyard";
   long_desc="You stand in an ancient graveyard.  The ground is soggy and "+
             "covered with strange moss.  To the north there is a large "+
             "granite structure, and to the west it is dark.\n";

   items=({"moss","It is an odd color of green",
   "ground","It is soggy ground",
   "structure","A large structure",
           "graveyard","It is old and in ill-repair"});
   dest_dir=({
   "/players/wilbie/barriers/entrance", "north",
   GPATH+"w_grave6", "west",
   GPATH+"w_grave2", "south",
   GPATH+"e_grave4", "east",
   });

 }
::reset(arg); replace_program("/room/room");
 }
