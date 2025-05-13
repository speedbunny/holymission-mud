inherit"room/room";
#include "/players/wilbie/def.h"
/*Wilbie*/

reset(arg){
   if(!arg){
   set_light(1);
   short_desc="In an ancient graveyard";
   long_desc="You stand in an ancient graveyard.  The ground is soggy and "+
             "covered with strange moss.  To the northwest there is a large "+
             "granite structure.\n";

   items=({"moss","It is an odd color of green",
   "ground","Soggy ground",
   "structure","A very large structure",
   "church","A large church",
   "cathedral","A large cathedral",
           "graveyard","It is old and in ill-repair"});
   dest_dir=({
   GPATH+"e_grave1", "north",
   GPATH+"e_grave7", "south",
   GPATH+"w_grave1", "west",
   });

 }
::reset(arg); replace_program("/room/room");
 }
