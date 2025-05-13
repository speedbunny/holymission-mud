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
   "grove","A grove of trees",
   "trees","Dismal looking trees",
   "structure","It is hard to see through the trees",
           "graveyard","It is old and in ill-repair"});
  dest_dir=({
  GPATH+"w_grave1", "east",
  GPATH+"w_grave7", "south",
  GPATH+"w_grave5", "north",
  });

  clone_list=({
  1,1,"zombie","/players/wilbie/graveyard/monsters/zombie",0,
 -1,1,"skull","/players/wilbie/graveyard/weapons/skull",0,
 -1,1,"robes","/players/wilbie/graveyard/armor/tatt_robes",0,
  });
  ::reset();
 }
::reset(arg); replace_program("/room/room");
 }
