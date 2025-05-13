/*
 * Author : Uglymouth
 * Date   : 8-AUG-1993
 */
#include "path.h"
inherit "room/room";

void reset(int arg) {
   if(arg) return;

   set_light(1);
   short_desc = "The northern corner of Main Street";
   long_desc = "You've arrived at the northern corner of Main Street. To the east lies\n"
         + "the village square. Main Street curves south here. Just outside the curve\n"
         + "lie some piles of treestems, waiting to be worked up, or to be sold.\n";
   dest_dir = ({ PATH+"square2","east",
         PATH+"street6","south" });
   items = ({ "main street","The major road through the village",
         "square","A cobblestone square forms the place where things happen in this village",
         "village square","A cobblestone square forms the place where things happen in this village",
         "corner","You can see obviously from the tracks here that this road is used often",
         "curve","The road curves from east to south here",
         "tracks","Tracks from people's feet, horses' hooves and wagon's wheels",
         "piles","Neatly stacked piles of treestems",
         "treestems","Woodsmen have cut them in the forest" });

  replace_program("room/room");
   }

