inherit "/room/room";
#include "/players/wilbie/def.h"

  object monst;

   reset(arg){
   if(!arg){

   set_light(0);

   short_desc="In the dungeon";
   long_desc=
   "The smell of rotting flesh makes your skin crawl here.  You notice a "+
   "small ladder leading up, and the smell seems to be coming from whatever "+
   "foul place it leads.\n";
   items=({
   "ladder","It leads up to a brighter area",
   "room","Not much to see here",
   "skin","You have goosebumps all over your skin",
   "flesh","You can't see the flesh, but you sure can smell it",
   "place","You will have to go up and find out",
   });
   smell="You almost fall over from the stench.";

   dest_dir=({
   GPATH+"hell3","north",
   GPATH+"hell5","up",
   });
}
::reset(arg); replace_program("/room/room");
}
