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
   "ground","Wet graveyard ground",
   "structure","It looks like a large church",
   "church","You can't see much of it from here",
           "graveyard","It is old and in ill-repair"});
   dest_dir=({
   GPATH+"w_grave3", "north",
   GPATH+"w_grave9", "west",
   GPATH+"e_grave11", "east",
   });
  clone_list=({
  1,3,"ghast","/players/wilbie/graveyard/monsters/ghast",0,
  1,2,"ghoul","/players/wilbie/graveyard/monsters/ghoul",0,
  });
  ::reset();

 }
::reset(arg); replace_program("/room/room");
 }
