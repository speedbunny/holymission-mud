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
   "ground","Soggy graveyard ground",
   "structure","It is hard to see it from here",
           "graveyard","It is old and in ill-repair"});
  dest_dir=({
  GPATH+"w_grave1", "north",
  GPATH+"w_grave3", "south",
  GPATH+"w_grave7", "west",
  GPATH+"e_grave7", "east",
  });

 }
::reset(arg); replace_program("/room/room");
 }
