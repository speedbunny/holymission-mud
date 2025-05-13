/*
 * Author : Uglymouth
 * Date   : 5-AUG-1993
 */

#include "path.h"
inherit "room/room";

void reset(int arg) {
   if(arg) return;

   set_light(1);
   short_desc = "The eastern part of Main Street";
   long_desc =  "You walk on the eastern part of Main Street, which is the\n" 
          + "biggest road through the village. East lies the gate to the\n"
          + "widerness. West you head for the village square. At the sides\n"
          + "of the road lie small gardens.\n";
   dest_dir=({
            PATH+"street2","east",
            PATH+"street4","west" });
   items=({
         "part","Main Street continues further west",
         "road","A well maintained dirt road",
         "village","A pleasant woodsmen village",
         "gate","A gate in the stockade is the entrance to the village",
         "stockade","A wall of pointed wooden poles to protect the village",
         "wilderness","You cannot see it through the closed gate",
         "square","A cobblestone square, just north of the church, is the centre of the village",
         "gardens","Small kitchen-gardens supply vegetables for the locals" });

  replace_program("room/room");
   }

