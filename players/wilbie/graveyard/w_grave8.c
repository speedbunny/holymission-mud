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
   "ground","A wet and soggy ground",
   "grove","A bunch of dismal looking trees",
   
   "trees","Dismal looking trees",
   "structure","You can barely see it from here",
           "graveyard","It is old and in ill-repair"});
   dest_dir=({
   GPATH+"w_grave7", "north",
   GPATH+"w_grave3", "east",
   GPATH+"w_grave9", "south",
   });

  clone_list=({
  1,2,"zombie","/players/wilbie/graveyard/monsters/zombie",0
  });
  ::reset();
 }
::reset(arg); replace_program("/room/room");
 }
