#include "abbey.h"
inherit "room/room";

reset(arg) {

  if (!arg) {
     set_light(1);
     short_desc="A Small room";
     long_desc="You are in a small, spartan bedroom.\n";
     dest_dir=({ PATH+"/m07","east" });
  }
}
