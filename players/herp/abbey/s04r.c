#include "abbey.h"
inherit "room/room";

reset(arg) {
int i;

  if (!arg) {
     set_light(1);
     short_desc="A small room";
     long_desc="You are in a small bedroom.\n";
     dest_dir=({ PATH+"/s04","west" });
  }
}
