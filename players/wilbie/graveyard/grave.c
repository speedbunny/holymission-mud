inherit "/room/room";
#include "/players/wilbie/def.h"

  object monst;

   reset(arg){
   if(!arg){

   set_light(0);

   short_desc="In the grave";
   long_desc=
   "You are in a recently opened grave.  The feeling of evil in the "+
   "area is somehow overshadowed by an aura of peace.\n";
   items=({
   "something","You wish you could see what you think is here",
   });
   smell="You smell brimstone.";

   clone_list=({
   1,1,"skeleton","/players/wilbie/graveyard/obj/skeleton",0,
  -1,1,"sword","/players/wilbie/graveyard/weapons/psword",0,
  -1,1,"leggings","/players/wilbie/graveyard/armor/parmor",0,
   });
   ::reset();

}
::reset(arg);
}

void init(){
  ::init();
   add_action("climb","climb");
           }

int climb(){
write("You climb out of the grave.\n");
this_player()->move_player("from the grave",GPATH+"painting");

return 1;
}
