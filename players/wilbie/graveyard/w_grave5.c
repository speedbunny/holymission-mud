inherit"room/room";
#include "/players/wilbie/def.h"
/*Wilbie*/

reset(arg){
   if(!arg){
   set_light(0);
   short_desc="In an ancient graveyard";
   long_desc="You stand in an ancient graveyard.  The ground is soggy and "+
   "covered in strange moss.  To the south is a dark grove of trees "+
   "and to the east is the wall of a large structure.\n";

   items=({"moss","It is an odd color of green",
   "ground","Soggy ground",
   "trees","Old, dismal looking trees",
   "grove","A bunch of old trees",
   "structure","You can't see much through the trees",
           "graveyard","It is old and in ill-repair"});
   dest_dir=({
   GPATH+"w_grave6", "south",
   });

  clone_list=({
  1,2,"ghast","/players/wilbie/graveyard/monsters/ghast",0,
  1,1,"ghoul","/players/wilbie/graveyard/monsters/ghoul",0,
  });
  ::reset();
 }
::reset(arg); replace_program("/room/room");
 }
