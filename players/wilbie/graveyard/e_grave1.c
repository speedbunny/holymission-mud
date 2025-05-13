inherit"room/room";
#include "/players/wilbie/def.h"
/*Wilbie*/

reset(arg){
   if(!arg){
   set_light(1);
   short_desc="In an ancient graveyard";
   long_desc="You stand in an ancient graveyard.  The ground is soggy and "+
             "covered with strange moss.  To the west there is a large "+
             "granite structure.\n";

   items=({"moss","It is an odd color of green",
   "ground","Soggy ground",
   "structure","A large cathedral",
   "cathedral","A large church",
   "church","A large structure",
           "graveyard","It is old and in ill-repair"});
   dest_dir=({GPATH+"e_grave2", "east",
              GPATH+"e_grave4", "south",
            });

  clone_list=({
  1,3,"zombie","/players/wilbie/graveyard/monsters/zombie",0,
 -1,1,"leather","/players/wilbie/graveyard/armor/rot_leath",0,
  });
  ::reset();
 }
::reset(arg); replace_program("/room/room");
 }
