/*
 * Author : Uglymouth
 * Date   : 9-AUG-1993
 */
#include "path.h"
inherit "room/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc = "The western part of Main Street";
  long_desc = "You walk on the western part of Main Street. West of you lies the\n"
        + "gate through which you can leave the safety of the village. Main\n"
        + "street continues to the east.\n";
  dest_dir = ({ PATH+"street9","east",
        PATH+"street11","west" });
  items = ({"main street","The major road through the village ends just west from here",
        "gate","The gate in the stockade forms the western exit from the village",
        "stockade","A wooden defense wall, made of sharply pointed poles",
        "village","A simple woodsmen's village",
        });
  replace_program("room/room");
  }

