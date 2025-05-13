/*
 * Author : Uglymouth
 * Date   : 8-AUG-1993
 */
#include "path.h"
inherit "room/room";

void reset(int arg) {
   if(arg) return;

   set_light(1);
   short_desc = "The southern corner of Main Street";
   long_desc = "You've arrived at the southern corner of Main Street. The road leads\n"
         + "north and west from here. West some more buildings lie on this road.\n" 
         + "To the east rises the wall of the village church.\n";
   dest_dir = ({ PATH+"street6","north",
         PATH+"street8","west" });
   items = ({ "main street","The major road through the village",
         "corner","Just another turn in the road",
         "buildings","Go there if you want to find out what they are",
         "wall","The curved wall surrounds the altar that stands within" });

  replace_program("room/room");
   }

