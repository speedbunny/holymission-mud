inherit"room/room";
#include "/players/wilbie/def.h"
/*Wilbie*/

reset(arg){
   if(!arg){
   set_light(1);
   short_desc="In an ancient graveyard";
   long_desc="You stand in an ancient graveyard.  The ground is soggy and "+
             "covered with strange moss.  To the northwest there is a large "+
  "granite structure.  The path continues to the north and south.\n";

   items=({"moss","It is an odd color of green",
   "ground","Soggy dirt covered with moss",
   "structure","A large church",
   "church","A large church",
   "path","A small path in the graveyard running north and south",
           "graveyard","It is old and in ill-repair"});
   dest_dir=({
   GPATH+"e_grave6", "north",
   GPATH+"e_grave10", "south",
   });

  clone_list=({
  1,1,"ghast","/players/wilbie/graveyard/monsters/ghast",0,
  -1,1,"arm","/players/wilbie/graveyard/weapons/arm",0,
  -1,1,"armour","/players/wilbie/graveyard/armor/rot_leath",0,
  });
  ::reset();
 }
::reset(arg); replace_program("/room/room");
 }
