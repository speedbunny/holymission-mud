inherit"room/room";
#include "/players/wilbie/def.h"
/*Wilbie*/

reset(arg){
   if(!arg){
   set_light(1);
   short_desc="In an ancient graveyard";
   long_desc="You are standing in the northeast corner of an ancient "+
   "graveyard.  The soggy ground is covered in a strange moss.  To the "+
   "northwest is some sort of large "+
             "granite structure.\n";

   items=({"moss","It is an odd color of green",
   "structure","A large cathedral",
   "cathedral","A very large church",
   "church","A very large, dark place",
   "ground","Soggy ground",
           "graveyard","It is old and in ill-repair"});
   dest_dir=({
   GPATH+"e_grave2", "west",
   GPATH+"e_grave6", "south",
   });

 }
::reset(arg); replace_program("/room/room");
 }
