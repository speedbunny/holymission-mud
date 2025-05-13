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
   "structure","It looks like an old church",
   "church","It is very large",
   "ground","It is soggy and covered with moss",
           "graveyard","It is old and in ill-repair"});
  dest_dir=({
  GPATH+"e_grave8", "north",
  GPATH+"e_grave12", "south",
  });

 }
::reset(arg); replace_program("/room/room");
 }
