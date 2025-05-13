inherit"room/room";
#include "/players/wilbie/def.h"
/*Wilbie*/

reset(arg){
   if(!arg){
   set_light(1);
   short_desc="In an ancient graveyard";
   long_desc="You stand in an ancient graveyard.  The ground is soggy and "+
   "the air is rather damp.  The forest to the northwest holds a large "+
   "structure made of granite, but you can't see what it is from here.\n";

   items=({"moss","It is an odd color of green",
   "ground","Wet, soggy ground",
   "air","It looks damp",
   "forest","It is a dark dismal forest",
   "structure","A large cathedral",
   "cathedral","A very large church of some sort",
   "church","A very large church",
           "graveyard","It is old and in ill-repair"});
   dest_dir=({
   GPATH+"e_grave3", "north",
   GPATH+"e_grave8", "south",
   });

 }
::reset(arg); replace_program("/room/room");
 }
