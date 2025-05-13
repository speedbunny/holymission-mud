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
    "ground","It is soggy and moss covered",
    "structure","A large church",
    "church","A large cathedral",
    "cathedral","A large structure",
           "graveyard","It is old and in ill-repair"});
  dest_dir=({
  GPATH+"w_grave2", "west",
  GPATH+"e_grave4", "north",
  GPATH+"e_grave9", "south",
  });

  clone_list=({
  1,4,"ghast","/players/wilbie/graveyard/monsters/ghast",0
  });
  ::reset();
 }
::reset(arg); replace_program("/room/room");
 }
