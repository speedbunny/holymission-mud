/*
 * Author : Uglymouth
 * Date   : 9-AUG-1993
 */
#include "path.h"
inherit "room/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc = "South of the village shop";
  long_desc = "North from this stroke of Main Street lies the door to the famous\n"
        + "'Tools & Things' shop. Main Street continues both to the east\n" 
        + "and to the west.\n";
  dest_dir = ({ PATH+"shop","north",
        PATH+"street8","east",
        PATH+"street10","west" });
  items = ({"main street","The major road through the village",
        "road","A well maintained dirt road",
        "shop","The general shop that serves this village",
        });

  replace_program("room/room");
  }

