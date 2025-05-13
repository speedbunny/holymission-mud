/*
 * Author : Uglymouth
 * Date   : 9-AUG-1993
 */
#include "path.h"
inherit "room/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc = "Southern Main Street";
  long_desc = "You walk on southern Main Street. East from here the road turns to\n"
        + "the north. In the distance you can see the western gate of the village.\n"
        + "The blind wall of a building decorates the north side of the road.\n";
  dest_dir = ({ PATH+"street7","east",
        PATH+"street9","west", 
        });
  items = ({"main street","The major road through the village",
        "road","A well maintained dirt road",
        "gate","A gate in the stockade that surrounds the village leads outside",
        "stockade","A wooden wall of pointed poles serves to keep any dangers out of the village",
        "wall","The southern wall of a building",
        "building","A shop of some kind. It has its entrance east from here",
        });

  replace_program("room/room");
  }

