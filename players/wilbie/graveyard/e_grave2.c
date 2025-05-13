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
   "structure","A large church",
   "church","A cathedral of some sort",
   "cathedral","A very large church",
   "ground","A very soogy ground",
           "graveyard","It is old and in ill-repair"});
    dest_dir=({
    GPATH+"e_grave3", "east",
    GPATH+"e_grave5", "south",
    GPATH+"e_grave1", "west",
    });

  clone_list=({
  1,1,"zombie","/players/wilbie/graveyard/monsters/zombie",0,
 -1,1,"leather","/players/wilbie/graveyard/armor/rot_leath",0,
  });
  ::reset();
 }
::reset(arg); replace_program("/room/room");
 }
