inherit "/room/room";
#include "/players/wilbie/def.h"

  object monst;

   reset(arg){
   if(!arg){

   set_light(0);

   short_desc="In the dungeon";
   long_desc=
   "You are in a dark and damp dungeon.  The sounds of screaming have gone "+
   "suddenly silent, as if something knows you are here.\n";
   items=({
   "dungeon","It is very dark down here",
   "something","You wish you could see what you think is here",
   });
   smell="You smell brimstone.";

   clone_list=({
   1,1,"skeleton","/players/wilbie/graveyard/obj/skeleton",0,
  -1,1,"sword","/players/wilbie/graveyard/weapons/psword",0,
   });
   ::reset();
   dest_dir=({
   GPATH+"hell2","south",
   "/players/wilbie/barriers/pit2","up",
   });
}
::reset(arg); replace_program("/room/room");
}
