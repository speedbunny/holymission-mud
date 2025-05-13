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
   "ground","A soggy graveyard ground",
   "structure","A large church of some sort",
   "church","A large, dark church",
           "graveyard","It is old and in ill-repair"});
   dest_dir=({
   GPATH+"e_grave7", "north",
   GPATH+"e_grave11", "south",
   GPATH+"w_grave3", "west",
   });

  clone_list=({
  1,3,"ghast","/players/wilbie/graveyard/monsters/ghast",0,
 -1,1,"skull","/players/wilbie/graveyard/weapons/skull",0,
  });
  ::reset();
 }
::reset(arg); replace_program("/room/room");
 }
