/*
 * Author : Uglymouth
 * Date   : 5-AUG-1993
 */
#include "path.h"
inherit "room/room";

void reset(int arg) {
   if(arg) return;

   set_light(1);
   short_desc = "At the crossroads";
   long_desc =  "You stand at a crossing. Main Street continues east and west.\n"
         + "To the north lies Rich Men's Road. South you can enter an obscure\n"
         + "little alley. \n";
   dest_dir = ({
              PATH+"road1","north",
              PATH+"street3","east",
              PATH+"alley1","south",
              PATH+"square1","west"   
              });
   items = ({
           "crossing","Here Main Street crosses Rich Men's Road and some obscure alley",
           "main street","The major road through the village",
           "rich men's road","This road owns its name to the kind of people living on it",
           "alley","Such an alley as where you'd expect either some mysterious little shop,\n"
                 + "or more likely, the local gang of thugs",
           });

  replace_program("room/room");
   }

